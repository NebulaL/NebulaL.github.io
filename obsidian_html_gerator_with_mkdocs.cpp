#include <iostream>
#include <io.h>
#include <string>
#include <fstream>
using namespace std;
string path,siteurl;

struct roam
{
	string name,insiteurl,wikilink,inline_wikilink;
	void g(string n,string url)
	{
		name=n;
		insiteurl=url+n;
		wikilink="[["+n+"]]";
		inline_wikilink="[["+n+"]]";
		return ;
	}
}obs[10005];

//遍历该目录下的.txt文件
int dir_custom(string path, string type)
{
	long hFile = 0; //句柄
	int cnt=0;
	struct _finddata_t fileInfo;
	string pathName,datad[10005];
	if ((hFile = _findfirst(pathName.assign(path).append("\\*.*").c_str(), &fileInfo)) == -1)
	{
		return;
	}
	do 
	{
		string fname = fileInfo.name;
		const char* s = fileInfo.name;
		const char* t = type.data();
 
		if (fileInfo.attrib&_A_SUBDIR) //是子文件夹
		{
//			cout << "[Folder]:" <<fileInfo.name << endl;
//			
//			//遍历子文件夹中的文件(夹)，查看是否有txt文件
			if(strcmp(s,".")==0 || strcmp(s,"..")==0) //子文件夹目录是.或者..
				continue;
			string sub_path = path + "\\" + fileInfo.name;
//			cout << sub_path << endl;
			dir_custom(sub_path, type);
 
		}
		else //判断是不是txt文件
		{
			
			if (strstr(s,t))
			{
				obs[cnt].g(fname,siteurl);
				cnt++;
				cout <<path+"\\"+fname << "\n";
 
			}
		}
	} while (_findnext(hFile,&fileInfo)==0);
	return cnt;
}
void c(roam a[],string path,int size)
{
	for(int i=0;i<size;i++)
	{
		string file_path = "G:\\1234.txt";//文件路径
		string out_path = "G:\\12345.txt";//输出路径
		string str;
		string::size_type pos = 0;
		ifstream instream;
		ofstream outstream;
		instream.open(file_path);
		if(!instream)
		cout<<"error"<<endl;
		outstream.open(out_path);
		while(getline(instream,str)){
		pos = str.find("hyu");//查找字符在string中第一次出现的位置
		if (pos==string::npos)//判断是否存在“hyu”这个字符
		{
			cout<<"Can not find this string !"<<endl;
		}
		else
		{
			str.replace(pos,3,"www");//用www替换hyu
			outstream<<str<<endl;
		}
		}
		instream.close();
		outstream.close();
	}
	
	return ;
}
bool FileStringReplace(ifstream &instream, ofstream &outstream)
{
	string str;
	size_t pos = 0;
	while (getline(instream, str)) // ���ж�ȡ
	{
		pos = str.find("Tom"); // ����ÿһ���е�"Tom"
		if (pos != string::npos)
		{
			str = str.replace(pos, 3, "Jerry"); // ��Tom�滻ΪJerry
			outstream << str << endl;
			continue;
		}
		outstream << str << endl;
	}
	return true;
}
int main()
{
	
	//给定目录
	
	cin>>path>>siteurl;
	//遍历该目录下的所有文件(夹)
	//输出该目录下的所有type类型的文件
	string type = ".md";
	dir_custom(path, type);
	//c(obs,"a",dir_custom(path, type));
	return 0;
}
