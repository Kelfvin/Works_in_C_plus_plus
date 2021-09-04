#include <iostream>
#include <fstream>
#include <string>
#include "Addition.h"

using namespace std;

int main()
{
    while (1)
    {
        ifstream fin;
        ofstream fout;

        cout << "Enter the xx.ini file's name:\n";
        string filename;
        cin >> filename;
        fin.open(filename);

        if (!fin.is_open())
        {
            cout << "Can't open the file!\nPlease check the filename!\n";
            exit(EXIT_FAILURE);
        }

        //存放每次读取的一行文本
        string temp_str;

        vector<Paragraph> txt;

        while (fin.good())
        {
            getline(fin, temp_str);

            //  如果是空行则继续提取下一行
            if (temp_str.length() <= 2)
            {
                continue;
            }

            else if (temp_str[0] == '[' && temp_str[temp_str.length() - 1] == ']') //  判断标题
            {
                Paragraph temp_paragraph;
                for (int i = 1; i < temp_str.length() - 1; i++)
                {
                    temp_paragraph.tittle += temp_str[i];
                }

                txt.push_back(temp_paragraph);
            }

            else if (temp_str[0] == ';')
            {
                continue;
            }

            else
            {
                int i = 0;
                Pair temp_pair;
                while (temp_str[i] != '=')
                {
                    temp_pair.key += temp_str[i];
                    i++;
                }

                i++;

                while (i < temp_str.length()&& i < temp_str.length())
                {
                    temp_pair.value += temp_str[i];
                    i++;
                }
                txt.back().content.push_back(temp_pair);
            }
        }

        fin.close();

        cout << "输入数字1列出所有小节命\n";
        cout << "输入2查找并显示指定段落\n";
        cout << "输入3查找指定段落中指定键的值\n";
        cout << "输入其他任意键来退出\n\n\n";
        cout << "现在输入你的选择[123 or any]:";

        int choice;
        cin >> choice;

        //  显示所有节
        if (choice == 1)
        {
            for (int i = 0; i < txt.size(); i++)
            {
                cout << txt[i].tittle << endl;
            }
        }

        else if (choice == 2)
        {
            cout << "输入你想要查找的段落的节的名称:";
            string target_title;
            cin >> target_title;
            bool flag = 0;
            int index;
            for (int i = 0; i < txt.size(); i++)
            {
                if (txt[i].tittle == target_title)
                {
                    flag = 1;
                    index = i;
                    break;
                }
            }

            if (flag)
            {
                for (int i = 0; i < txt[index].content.size(); i++)
                {
                    cout << txt[index].content[i].key << '=' << txt[index].content[i].value << endl;
                }
            }

            else
                cout << "没有找到相应的段落！\n";
        }

        else if (choice == 3)
        {
            cout << "输入你想要查找的段落的节以及键的名称:";
            string target_title, target_key;
            cin >> target_title >> target_key;
            bool flag = 0;
            int index;
            for (int i = 0; i < txt.size(); i++)
            {
                if (txt[i].tittle == target_title)
                {
                    flag = 1;
                    index = i;
                    break;
                }
            }

            if (flag)
            {
                for (int i = 0; i < txt[index].content.size(); i++)
                {
                    if (txt[index].content[i].key == target_key)
                    {
                        cout << txt[index].content[i].value<<endl;
                        break;
                    }
                }
            }

            else
                cout << "没有找到相应的段落！\n\n";

        }

        else
            return 0;
    }

        return 0;
}
