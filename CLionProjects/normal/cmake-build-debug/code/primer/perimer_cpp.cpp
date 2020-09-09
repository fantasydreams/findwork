//
// Created by Sharwen on 2020/2/11.
//

#include "../../header/primer_header.h"


//14.1
std::istream& operator>>(std::istream &cin, sale_data & s) {
    cin >> s.price;
    return cin;
}

std::ostream & operator << (std::ostream & cout,const sale_data & s){
    cout << s.price;
    return cout;
}

//13.39

strVec::strVec(std::initializer_list<std::string> i_l){
    auto sec = alloc_n_copy(i_l.begin(),i_l.end());
    _first_elem = sec.first;
    _first_free = sec.second;
    _cap = _first_free;
}

strVec::strVec(const strVec & obj){
    std::pair<std::string *,std::string *> sec = alloc_n_copy(obj.begin(),obj.end());
    _first_elem = sec.first;
    _first_free = _cap = sec.second;
}

strVec& strVec::operator=(const strVec &obj){
    std::pair<std::string *,std::string *> sec = alloc_n_copy(obj.begin(),obj.end());
    free();
    _first_elem = sec.first;
    _first_free = _cap = sec.second;

    return *this;
}

void strVec::push_back(const std::string &str){
    check_n_allocator();
    _alloc.construct(_first_free++,str);
}


void strVec::reallocate(){
    size_t cap = size() ? 2 * size() : 1;
    auto new_space = _alloc.allocate(cap);
    auto dest = new_space;
    for(auto iter = begin();iter !=end();++iter){
        _alloc.construct(dest++,std::move(*iter++));
    }
    free();
    _first_elem = new_space;
    _first_free = dest;
    _cap = _first_elem + cap;

}

std::pair<std::string *,std::string *> strVec::alloc_n_copy(const std::string *b,const std::string *e){
    auto space = _alloc.allocate(e-b);

    return {space,uninitialized_copy(b,e,space)};

}

void strVec::free() {
    if(begin()){
        for(auto iter = end();iter != begin();++iter){
            _alloc.destroy(--iter);
        }

        //_alloc.deallocate(begin(),capacity());
        for_each(begin(), end(), [this](std::string &rhs){ _alloc.destroy(&rhs); });
    }
}


//12.30

void Query_res_print(std::ostream & out,const QueryResult & qr){
    out << "elements " << qr._query_word << " occurs " << qr._count << ((qr._count <= 1) ? " time ":" times") << std::endl;
    auto line_iter = qr._line_number->cbegin();
    while(line_iter != qr._line_number->cend()){
        std::cout << "line(" << *line_iter << ") " << *(qr._text->cbegin() + *line_iter - 1) << std::endl;
        ++line_iter;
    }
}


QueryResult TextQuery::query(std::string word) {
    std::shared_ptr<std::set<size_t>> noRes(std::make_shared<std::set<size_t >>());
    auto iter = _word.find(word);
    if(iter == _word.cend()){
        return QueryResult(word,0,_file,noRes);
    }else{
        return QueryResult(word,iter->second.first,_file,iter->second.second);
    }
}

TextQuery::TextQuery(std::string file_name):_file(std::make_shared<std::vector<std::string>>()){
    std::ifstream  in(file_name);
    if(!in) return;

    std::string str;
    while(getline(in,str)){
        _file->push_back(str);
        std::transform(str.begin(),str.end(),str.begin(),::tolower);
        std::istringstream ss(str);
        std::string w;
        while(ss >> w){
            auto iter =  _word.find(w);
            if(iter == _word.end()){
                _word[w] = std::pair<size_t,std::shared_ptr<std::set<size_t >>> (1,std::make_shared<std::set<size_t>>());
                _word[w].second->insert(_file->size());
            }else{
                (iter->second.first)++;
                iter->second.second->insert(_file->size());
            }
        }
    }

}


void Text::query(std::string str){
    auto iter = word.find(str);
    if(iter == word.cend()) return;

    std::cout <<"element " <<str << " occurs " << iter->second.first << ((iter->second.first > 1)? " times" : " time") << std::endl;
    auto line_iter = iter->second.second.cbegin();
    while(line_iter != iter->second.second.cend()){
        std::cout << "line(" << *line_iter << ") " << text[*line_iter - 1] << std::endl;
        ++line_iter;
    }
}


#ifdef __DEBUG__
void print_vector(const Text & t){
    auto cbegin = t.text.cbegin(),cend = t.text.cend();
    while(cbegin != cend){
        std::cout << *cbegin << std::endl;
        ++cbegin;
    }
}



void print_word(const Text & t){
    auto cbegin = t.word.cbegin(),cend = t.word.cend();
    while(cbegin != cend){
        std::cout << cbegin->first << " "<<cbegin->second.first <<std::endl;
        print_through_iterator(cbegin->second.second.cbegin(),cbegin->second.second.cend());
        std::cout <<std::endl;

        ++cbegin;
    }
}
#endif


//12.27
Text::Text(){};
Text::Text(std::string file_name) {
    f_n = file_name;
    std::ifstream in(f_n);
    if(!in) return;

    std::string str;
    std::set<size_t> df;
    size_t line_number = 1;
    while(std::getline(in,str)){
        text.push_back(str);
        std::transform(str.begin(),str.end(),str.begin(),::tolower);
        std::istringstream ss(str);
        while(ss>>str){
            auto iter = word.find(str);
            if(iter != word.end()){
                iter->second.first++;
                iter->second.second.insert(line_number);
            }else{
                word[str] = std::pair<size_t,std::set<size_t>>(1,df);
                word[str].second.insert(line_number);
            }
        }

        ++line_number;
    }

}

//10.24
void is_string(){
    size_t size;
    std::cin >> size;
    if(size <= 0) return;

    char * str = new char[size + 1];
    std::istream_iterator<char> is_in(std::cin),eof;
    for(size_t i=0;i<size && is_in != eof;++i){
        str[i] = *is_in++;
    }

    std::cout << str << std::endl;
    delete[] str;

}

//10.23
std::string concate_string(const std::string &s1,const std::string &s2){
    std::string str = s1 + s2;
    return str;
}

size_t get_str_len(const char * s){
    size_t size = 0;
    while(*s++){
        ++size;
    }

    return size;
}

char * concate_charstring(const char *s1,const char * s2){

    size_t  len = get_str_len(s1) + get_str_len(s2)+1;
    char * str = new char[len];
    str[len-1] = 0;

    size_t  idx = 0;
    while(*s1){
        str[idx++] = *s1++;
    }

    while(*s2){
        str[idx++] = *s2++;
    }

    return str;

}

//12.16
//void test_unique_copy(){
//    std::unique_ptr<int> p (new int (20));
//    std::unique_ptr<int>  q = p;
//}

//12.10
void shared_ptr_process(std::shared_ptr<int> p){
    std::cout << p.use_count() << std::endl;
}

//12.7
std::shared_ptr<std::vector<int>>  new_int_vec_shared_ptr(){
    std::shared_ptr<std::vector<int>> p = std::make_shared<std::vector<int>>();
    return p;

}

//12.6
std::vector<int> * new_int_vec(){
    return new(std::nothrow) std::vector<int>;
}

//12.2

strBolb::strBolb():data(std::make_shared<std::vector<std::string>>()){};

strBolb::strBolb(std::initializer_list<std::string> il):strBolb(){
    for(auto iter : il){
        data->push_back(iter);
    }
}

void strBolb::pop_back() {
    if(!data->empty()){
        data->pop_back();
    }
}

std::string & strBolb::front(){
    if(data->empty()){
        throw new std::exception;
    }
    return data->front();
}

std::string strBolb::front() const{ //此const重载由对象是否是const对象决定，如果是const对象则调用const版本。
    if(data->empty()){
        throw new std::exception;
    }

    return data->front();
}

std::string &strBolb::back() {
    if(data->empty()){
        throw new std::exception;
    }

    return data->back();
}

std::string strBolb::back()const {
    if(!data->empty()){
        throw new std::exception;
    }

    return data->back();
}

//11.38
void process_rule_unordermap(std::string rulename,std::unordered_map<std::string,std::string> &rule_map){
    std::ifstream in_rule(rulename);
    if(!in_rule) return;

    std::string line,key,value;
    while(std::getline(in_rule,line)){
        std::stringstream ss(line);
        ss >> key;
        auto pos = line.find_first_not_of(" ",key.size());
        if(pos == std::string::npos) continue;
        value = line.substr(pos,line.size());
        if(value.size()){
            rule_map[key] = value;
        }
    }

}


void exchange_text_unorder_map(std::string textname,std::string rulename){
    std::ifstream text(textname);
    if(!text)return;

    std::unordered_map<std::string,std::string> rule;
    process_rule_unordermap(rulename,rule);

    //print_map_or_pair(rule.cbegin(),rule.cend());

    std::string line,word;
//    std::stringstream ss;
    while(getline(text,line)){
//        ss.clear();
//        ss << line;
        std::stringstream ss(line);
        while(ss >> word){
            if(rule.count(word)){
                std::cout << rule[word];
            }else{
                std::cout << word;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

}

//11.33


void process_rule_map(std::string rulename,std::map<std::string,std::string> &rule_map){
    std::ifstream in_rule(rulename);
    if(!in_rule) return;

    std::string line,key,value;
    while(std::getline(in_rule,line)){
        std::stringstream ss(line);
        ss >> key;
        auto pos = line.find_first_not_of(" ",key.size());
        if(pos == std::string::npos) continue;
        value = line.substr(pos,line.size());
        if(value.size()){
            rule_map[key] = value;
        }
    }

}


void exchange_text_map(std::string textname,std::string rulename){
    std::ifstream text(textname);
    if(!text)return;

    std::map<std::string,std::string> rule;
    process_rule_map(rulename,rule);

    //print_map_or_pair(rule.cbegin(),rule.cend());

    std::string line,word;
//    std::stringstream ss;
    while(getline(text,line)){
//        ss.clear();
//        ss << line;
        std::stringstream ss(line);
        while(ss >> word){
            if(rule.count(word)){
                std::cout << rule[word];
            }else{
                std::cout << word;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

}


//11.13
void make_pair_string_int(std::vector<std::pair<std::string,int>> &vec){
    std::string str; int num;
    for(int i=0;i<5;++i){
        std::cin >> str >> num;
        vec.push_back(std::pair<std::string,int>(str,num));
    }
}




//11.3
void count_words(const std::string &filename,
        std::map<std::string,unsigned int> &dict,const std::set<std::string>& exclude){
    std::ifstream in(filename);
    if(!in) return;

    std::istream_iterator<std::string> is_in(in),eof;

    std::string str;
    while(is_in != eof){
        str = *is_in++;
        std::transform(str.begin(),str.end(),str.begin(),::tolower); //string类中没有默认提供tolower的方法，使用transform来完成
        if(exclude.find(*is_in) == exclude.cend()){
            ++dict[*is_in];
        }
    }

}


//10.42
void list_unique(std::list<std::string> &text,std::string filename){
    std::ifstream in(filename);
    if(!in)return;

    std::istream_iterator<std::string> is_in(in),eof;
    std::copy(is_in,eof,std::back_inserter(text));
    text.sort();
    text.unique();

}

//10.36
auto find_last_elem(std::vector<int> numbers,int val)->std::vector<int>::const_iterator{
    auto iter = std::find(numbers.crbegin(),numbers.crend(),val);
    //print_through_iterator(iter,numbers.crend());
    return iter.base(); //返回的base迭代器有问题不知道为什么？？？
}

//10.34


//10.33
void iostream_iterator_to_file(const std::string & in_filename,
        const std::string &out_file_name1,
        const std::string &out_file_name2){
    std::ifstream in(in_filename);
    std::ofstream out1(out_file_name1);
    std::ofstream out2(out_file_name2);

    if(!in || !out1 || !out2){
        return;
    }

    std::istream_iterator<int> is_in(in),eof;
    std::ostream_iterator<int> os_out1(out1," ");
    std::ostream_iterator<int> os_out2(out2,"\n");

    while(is_in != eof){
        int val = *is_in++;
        if(val & 0x1){
            *os_out1++ = val;
        }else{
            *os_out2++ = val;
        }
    }

}

//10.31
void iostream_iterator_unique(const std::string & filename){
    std::ifstream in(filename);
    if(!in) return;
    std::istream_iterator<int> ios(in),eof;
    std::ostream_iterator<int> out(std::cout," ");
    std::vector<int> vec;
    std::copy(ios,eof,std::inserter(vec,vec.begin()));
    std::sort(vec.begin(),vec.end());
    std::unique_copy(vec.cbegin(),vec.cend(),out);
}

//10.30
void iostream_iterator(const std::string &filename){
    std::ifstream in(filename);
    if(!in) return;
    std::istream_iterator<int> ios(in),eof;
    std::ostream_iterator<int> out(std::cout," ");

    std::copy(ios,eof,out);
//    while(ios != eof){
//        out = *ios++;
//    }

}

//10.29
void istream_iterator_vec(std::vector<std::string>& vec,std::string filename){
    std::ifstream file(filename);
    if(!file) return;
    std::istream_iterator<std::string> in(file),eof;
    std::copy(in,eof,std::inserter(vec,vec.begin()));
}

//10.28
void three_inserter(const std::vector<int> &numbers){
    std::deque<int> vec1,vec2,vec3;

    std::copy(numbers.cbegin(),numbers.cend(),std::front_inserter(vec1));
    for(auto val : vec1){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::copy(numbers.cbegin(),numbers.cend(),std::inserter(vec2,vec2.begin()));
    for(auto val : vec2){
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::copy(numbers.cbegin(),numbers.cend(),std::back_inserter(vec3));
    for(auto val : vec3){
        std::cout << val << " ";
    }
    std::cout << std::endl;

}

//10.27
void unique_copy_v_to_l(std::vector<std::string> text, std::list<std::string> &List){
    std::sort(text.begin(),text.end());
    std::unique_copy(text.cbegin(),text.cend(),std::inserter(List,List.begin())); // unique_copy 需要sort之后才生效
}

//10.24

bool over_len(const std::string & str, int Size){
    if(str.size() > Size){
        return true;
    }
    return false;
}

std::string my_find_if(const std::vector<std::string> & text, const std::string & str){
    auto iter = std::find_if(text.cbegin(),text.cend(),std::bind(over_len,std::placeholders::_1,str.size()));
    if(iter != text.cend()){
        return *iter;
    }

    return "";
}




//10.23

void over_length(const std::string & str, unsigned int len, unsigned int & count){
    if(str.size() > len){
        ++count;
    }
}

unsigned long long count_words_overlength(const std::vector<std::string> & text, unsigned int len){
    unsigned int count = 0;
    std::for_each(text.cbegin(),text.cend(),std::bind(over_length,std::placeholders::_1,len,std::ref(count)));  //bind 添加引用参数时必须使用std::ref(para)
    return count;
}

