/*
計算要傳送某個訊息一共要按幾次按鍵。
本題所使用的手機鍵盤排列如下。

---------------------

|      | abc | def  |

---------------------

| ghi  | jkl | mno  |

---------------------

| pqrs | tuv | wxyz |

---------------------

|      | <SP>|      |

---------------------

上圖的每個格子代表一個按鍵。SP 代表空白。 
如果要打 'a'，我們要按那個鍵一次，但是如果要打 'b' 則要按相同的鍵兩次，
'c' 的話三次。相同的 'd' 按一次，'e' 兩次，'f' 三次。餘此類推。空白只要按一次即可。

輸入的第一行有一個正整數 T，代表有幾組測資。
接下來的 T 行只含空白及小寫字母。每行至少 1 個最多 100 個字元。

*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;//測資比數
    cin >> t;
    int i=0;
    cin.get();//清除緩衝區
    while (i < t)
    {
       
        string send_msg;
        int loop_counter;
        getline(cin, send_msg);
        int press = 0;
        for (loop_counter = 0; loop_counter < send_msg.length(); loop_counter++)
        {
            if (!islower(send_msg[loop_counter]))//非小寫字母
            {
                if(send_msg[loop_counter]==' ')//空白，按一次
                    press++;
                continue;
            }
            int char_eq_ascii = int(send_msg[loop_counter]);
            switch (send_msg[loop_counter])
            {
            case 'a':case 'd':case 'g':case 'j':case 'm':case 'p':case 't':case 'w':
                press+=1;
                break;
            case 'b':case 'e':case 'h':case 'k':case 'n':case 'q':case 'u':case 'x':
                press += 2;
                break;
            case 'c':case 'f':case 'i':case 'l':case 'o':case 'r':case 'v':case 'y':
                press += 3;
                break;
            case 's':case 'z':
                press += 4;
                break;
            default:
                break;
            }
                    
        }
        /*結束，初始化*/
        cout << "Case #"<<i+1<<": "<<press<<endl;
        i++;
        
    }
    

}


