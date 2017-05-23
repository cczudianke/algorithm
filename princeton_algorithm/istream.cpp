// istream::get example
#include <iostream>     // std::cin, std::cout
#include <fstream>      // std::ifstream
#include <vector>
#include <string>
#include <utility>
using namespace std;
vector< pair<pair<int,int>,string> > log;
int readlogfile() 
{	
	std::ifstream is("test.txt");     // open file
	char c;
	int flag = 0;
	while (is.get(c)) {
		int p1,p2;
		string timestrap;
		if(flag==0){
//			cout<<c<<endl;
			p1 = c -'0';
//			cout<<p1<<endl;
			flag++;
			is.get(c); //remove backspace
		}
		else if(flag==1){
//			cout<<c<<endl;
			p2 = c -'0';
//			cout<<p2<<endl;
			flag++;
//			is.get(c); //remove backspace
		}
		else if(flag==2){
			while(is.get(c)){
				if(c == '\n'){
					flag = 0;
//					cout<<p1<<" "<<p2<<endl;
					pair<int,int> friendship (p1,p2);
//					cout<<friendship.first<<" "<<friendship.second<<endl;
					pair<pair<int,int>,string> one_log (friendship,timestrap);
//					cout<<one_log.first.first<<" "<<one_log.first.second<<endl;
					log.push_back(one_log);
//					pair<int,int> my_out(log[0].first);
//					cout<<get<0>(my_out)<<" "<<my_out.second<<endl;
					break;
				}else if(is.peek()==EOF){ //使用char变量读取文件时,is.peek()判断EOF的效果较好 
					timestrap.push_back(c);
//					cout<<"EOF"<<endl;
					pair<int,int> friendship (p1,p2);
//					cout<<friendship.first<<" "<<friendship.second<<endl;
					pair<pair<int,int>,string> one_log (friendship,timestrap);
//					cout<<one_log.first.first<<" "<<one_log.first.second<<endl;
					log.push_back(one_log);
//					pair<int,int> my_out(log[0].first);
//					cout<<get<0>(my_out)<<" "<<my_out.second<<endl;
					break;
				}
				else{
					timestrap.push_back(c);
				}
			}
		}
	}

//	for(vector<pair<pair<int,int>,string> >::iterator it = log.begin();it != log.end();++it){
//		cout<< (it->first).first<< " " << (it->first).second<<" "<<it->second << endl;
//		cout<<'\n'<<endl;
//	}
	is.close();                // close file

	return 0;
}
