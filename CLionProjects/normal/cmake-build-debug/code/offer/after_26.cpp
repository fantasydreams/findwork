//
// Created by Sharwen on 2020/2/24.
//
#include "../../header/offer/after_26.h"




int get_ulgy_number(int index){
    std::vector<int> ulgy_number(index);

    int idx2 = 0,idx3=0,idx5 = 0;
    int next = 1;
    ulgy_number[0] = 1;

    while(next < index){
        int next_ulgy = std::min(std::min(ulgy_number[idx2] * 2 ,ulgy_number[idx3] * 3),ulgy_number[idx5] * 5);
        ulgy_number[next++] = next_ulgy;
        while(ulgy_number[idx2] * 2 <= next_ulgy){
            ++idx2;
        }

        while(ulgy_number[idx3] * 3 <= next_ulgy){
            ++idx3;
        }

        while(ulgy_number[idx5] * 5 <= next_ulgy){
            ++idx5;
        }
    }

    return ulgy_number[next-1];
}

std::string find_min_combine_number(std::vector<std::string> numbers){
    if(numbers.size() == 0){
        return "";
    }

    std::sort(numbers.begin(),numbers.end(),[](std::string n1,std::string n2){return (n1+n2 < n2 + n1);});

    std::string res;
    for(auto val : numbers){
        res += val;
    }
    return res;
}


unsigned long long count_one(int num,int k){
    int high = num,low,cur;
    unsigned long long res = 0;
    for(int i=1;high;++i){
        high = num / pow(10,i);
        int tmp = num / pow(10,i-1);
        cur = tmp % 10;
        low = num - tmp * pow(10,i-1);

        if(cur > k){
            res += (high + 1) * pow(10,i-1);
        }else if(cur < k){
            res += high * pow(10,i-1);
        }else{
            res += high * pow(10,i-1);
            res += low + 1;
        }
    }

    return res;
}


int continuous_max_sum(const std::vector<int>& numbers){
    if(numbers.size() == 0){
        return 0;
    }

    int max_sum = numbers[0];
    int cur_sum = max_sum;

    for(auto iter = numbers.cbegin() + 1;iter < numbers.cend();++iter){
        if(cur_sum + *iter <= 0){
            cur_sum = 0;
        }else{
            cur_sum += *iter;
        }

        if(cur_sum > max_sum){
            max_sum = cur_sum;
        }
    }

    return max_sum;
}

void get_last_numbers(const std::vector<int> &numbers,std::set<int,std::greater<int>> &last_k,int k){
    if(k <=0 ){
        return;
    }

    for(auto val : numbers){
        if(last_k.size() < k){
            last_k.insert(val);
        }else{
            auto iter = last_k.begin();
            if(*iter > val){
                last_k.erase(iter);
                last_k.insert(val);
            }
        }
    }
}

bool is_more_than_half(std::vector<int> &number,int num){
    int times = 0;
    for(int i=0;i<number.size();++i){
        if(number[i] == num){
            ++times;
        }
    }

    if(times > (number.size() >> 1)){
        return true;
    }else{
        return false;
    }
}


bool more_than_half(std::vector<int> &number,int & result){
    if(number.size() == 0){
        return false;
    }

    int times = 1;
    int res = number[0];

    for(int i=1;i<number.size();++i){
        if(times == 0){
            times = 1;
            res = number[i];
        }

        if(number[i] == res){
            ++times;
        }else{
            --times;
        }
    }

    result = res;
    return is_more_than_half(number,res);

}

void permuation(std::string &str,size_t entrance){
    if(entrance == str.size()){
        std::cout << str << std::endl;
    }

    for(int i=entrance;i<str.size();++i){
        std::swap(str[entrance],str[i]);
        permuation(str,entrance+1);
        std::swap(str[entrance],str[i]);
    }
}

void permuation(std::string &str){
    permuation(str,0);
}


void print_binary_list(binary_t_node * root){
    binary_t_node * reverse = root;
    while(root){
        std::cout << root->_val << " ";
        if(root->_pright == nullptr){
            reverse = root;
        }
        root = root->_pright;
    }

    std::cout << std::endl;

    while(reverse){
        std::cout << reverse->_val << " ";
        reverse = reverse->_pleft;
    }

}

void print_binary_search_tree(binary_t_node * root){
    if(!root){
        return;
    }
    std::cout<<root->_val <<" ";
    print_binary_search_tree(root->_pleft);
    print_binary_search_tree(root->_pright);
}

void binary_search_tree_insert(binary_t_node * &root,int val){
    if(!root){
        root = new binary_t_node(val);
        return;
    }
    if(root->_val > val){
        binary_search_tree_insert(root->_pleft,val);
    }else{
        binary_search_tree_insert(root->_pright,val);
    }
}

void convert_binary_search_tree_to_list(binary_t_node * root,binary_t_node *&last_node){
    if(!root){
        return;
    }

    convert_binary_search_tree_to_list(root->_pleft,last_node);
    root->_pleft = last_node; // 这里两句一定是不需要判断为空指针的，因为就算是不是空指针，所指向的内容也不一定是她的前驱或者后继

    if(last_node != nullptr){   //这里要注意为null的情况
        last_node->_pright = root;
    }

    last_node = root;

    convert_binary_search_tree_to_list(root->_pright,last_node);
}

binary_t_node * convert_binary_search_tree_to_list(binary_t_node * head){
    binary_t_node *last_node = nullptr;
    convert_binary_search_tree_to_list(head,last_node);

    while(head ->_pleft){
        head = head->_pleft;
    }
    return head;
}



void double_complex_node(complex_forward_list_node * head){
    complex_forward_list_node * p = head;
    complex_forward_list_node * new_node;
    while(p){
        new_node = new complex_forward_list_node(p->_val);
        new_node->_pnext = p->_pnext;
        p->_pnext = new_node;
        p=new_node->_pnext;
    }
}

void set_complext_list_sib(complex_forward_list_node * head){
    complex_forward_list_node * p = head;
    while(p){
        if(p->_psib){
            p->_pnext->_psib = p->_psib->_pnext;
        }

        p = p->_pnext->_pnext;
    }
}

complex_forward_list_node * seperate_new_complex_list(complex_forward_list_node * head){
    if(!head){
        return nullptr;
    }
    complex_forward_list_node * p = head;
    complex_forward_list_node * new_head = head->_pnext;
    complex_forward_list_node * new_node = new_head;

    if(p){
        p->_pnext = new_node->_pnext;
        p = new_node->_pnext;
    }

    while(p) {
       new_node->_pnext = p->_pnext;
       new_node = new_node->_pnext;
       p->_pnext = new_node->_pnext;
       p = p->_pnext;
    }

    return new_head;

}

complex_forward_list_node * copy_complex_forward_list(complex_forward_list_node * head){
    if(!head){
        return nullptr;
    }

    double_complex_node(head);
    set_complext_list_sib(head);
    return seperate_new_complex_list(head);
}


bool check_sib(std::vector<int> & sib){
    for(auto val : sib){
        if(val >= (int)sib.size()){
            return false;
        }
    }
    return true;
}

complex_forward_list_node * create_complext_forward_list(const std::vector<int> &list,std::vector<int> &sib){
    if(list.size() == 0 || list.size() != sib.size() || !check_sib(sib)){
        return nullptr;
    }

    complex_forward_list_node * head = new complex_forward_list_node(list[0]);
    complex_forward_list_node * p = head;

    std::vector<complex_forward_list_node *> addr;
    addr.push_back(head);
    for(int i=1;i<list.size();++i){
        p->_pnext = new complex_forward_list_node(list[i]);
        addr.push_back(p->_pnext);
        p=p->_pnext;
    }

    p = head;
    for(int i=0;i<sib.size();++i){
        p->_psib = (sib[i] == -1) ? nullptr : addr[sib[i]];
        p=p->_pnext;
    }

    return head;
}


void print_complext_forward_list(complex_forward_list_node * head){
    complex_forward_list_node * p = head;
    while(p){
        std::cout <<"val:" << p->_val << " sib:";
        if(p->_psib){
            std::cout << p->_psib->_val << std::endl;
        }else{
            std::cout<< "null" << std::endl;
        }

        p=p->_pnext;
    }
}


void destroy_complext_forward_list(complex_forward_list_node * head){
    while(head){
        complex_forward_list_node * p = head;
        head=head->_pnext;
        delete p;
    }
}