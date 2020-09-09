#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>


//void reverser_file_content(const std::string &  file_name);
std::set<std::string,std::greater<std::string>> find_top_k_ipaddr(const std::string &file_name,int k);
void print(const std::set<std::string,std::greater<std::string>> & res);

int main() {

    //reverser_file_content("./test");
    std::set<std::string,std::greater<std::string>> res = find_top_k_ipaddr("./test",-1);
    print(res);

    return 0;
}


void print(const std::set<std::string,std::greater<std::string>> & res){
    for(auto ipaddr : res){
        std::cout << ipaddr <<std::endl;
    }
}

std::set<std::string,std::greater<std::string>> find_top_k_ipaddr(const std::string &file_name,int k){
    std::set<std::string,std::greater<std::string>> top_k_ipaddr;
    if(file_name.size() == 0 || k<=0){
        return top_k_ipaddr;
    }

    std::ifstream file_in(file_name);
    if(!file_in){
        return top_k_ipaddr;
    }

    std::string ipaddr;
    while(getline(file_in,ipaddr)){
        if(top_k_ipaddr.size() < k){
            top_k_ipaddr.insert(ipaddr);
        }else{
            top_k_ipaddr.insert(ipaddr);
            auto smallest = top_k_ipaddr.begin();
            top_k_ipaddr.erase(smallest);
        }
    }

    return top_k_ipaddr;
}



















//void reverser_file_content(const std::string &  file_name){
//    if(file_name.size() == 0) {
//        return;
//    }
//
//    std::ifstream file_in(file_name);
//
//    std::string tmp = file_name + "_tmp";
//    std::ofstream file_out(tmp);
//
//    if(!file_in){
//        return;
//    }
//
//    std::string str;
//    while(getline(file_in,str)){
//        std::reverse(str.begin(),str.end());
//        file_out << str;
//        if(!file_in.eof()){
//            file_out << std::endl;
//        }
//    }
//
//    file_in.close();
//    file_out.close();
//
//    std::ifstream in(tmp);
//    std:std::ofstream out(file_name);
//    if(!in){
//        return;
//    }
//
//    while(getline(in,str)){
//        out << str;
//        if(!in.eof()){
//            out << std::endl;
//        }
//    }
//
//    in.close();
//    out.close();
//
//}