#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/*
* 測資:L2L2T10T11EE=>7
*/
int totalPath = 0;
int GetNum(char* commands, int offset)//取指令之間的數字值(char轉int)
{

    int sum = 0, imove = 1;
    while (commands[offset + imove] >= 48 && commands[offset + imove] <= 57)
    {
        //printf("%c \n",commands[offset+imove]);
        sum *= 10;
        sum += commands[offset + imove] - 48;
        imove++;
    }
    return sum;
}
void DetectPath(char* commands, int offset)//(指令開頭位址,偏移量,總位移量)
{
    static int Step[2] = { -1,-1 },FLAG=0;//不會因為結束函數重置出值，儲存上一次T的結果，做奇偶判斷決定怎麼加回傳位移
    if (FLAG == 0)
    {
        Step[0] = GetNum(commands, offset);
        if (Step[1] != -1)
        {
            totalPath += abs(Step[1] - Step[0]); //printf("%d\n", totalPath);
        }
        FLAG = 1;
    }
    else if (FLAG == 1)
    {
        Step[1] = GetNum(commands, offset); 
        totalPath += abs(Step[1] - Step[0]);
        FLAG = 0;
    }
    //printf("%d\n", totalPath);
}
int Eloop(char* commands,int Lx, int offset,int flag)//(指令開頭位址,loop重複幾次(即L後面的個位數字),偏移量)
{
    
    //為了使迴圈不影響真正的offset，故再複製一個
    
    
    int loopath=0;
    int temp_offset = offset + 1;//剛進函式時offset是指向L後面那個數字(Lx)，加1再判斷
    int head = GetNum(commands, temp_offset);
        while (*(commands + temp_offset) != 'E')
        {
            if (*(commands + temp_offset) == 'L')//loop內又嵌套一個loop
            {
                temp_offset =Eloop( commands,commands [temp_offset + 1] - '0', temp_offset +1,1);
            }
            else if (*(commands + temp_offset) == 'T')
            {
                if (flag)
                {
                    int x0 = totalPath;
                    DetectPath(commands, temp_offset);
                    loopath += totalPath - x0;
                    totalPath =x0;
                    temp_offset += 2;
                    
                }
                else
                {
                    DetectPath(commands, temp_offset);
                    temp_offset += 2;
                    flag++;
                }
                
            }
            temp_offset++;
        }
    int tail= GetNum(commands, temp_offset - 3);
    printf("AA%dbb\n", loopath);
    totalPath += loopath * Lx  + abs(tail - head) * (Lx - 1);
    return temp_offset;
    
}
int main() {
    char nowBit;
    char* commands = NULL;
    commands = (char*)malloc(1 * sizeof(char));
    int MAXINDEX = 0;
    while (scanf("%c", &nowBit) != EOF)//scan commands
    {
        commands = (char*)realloc(commands, (MAXINDEX + 1) * (sizeof(char)));
        commands[MAXINDEX] = nowBit;
        MAXINDEX++;

    }
    //    printf("%d",MAXINDEX);
    //int  totalPath = 0;
    for (int i = 0; i < MAXINDEX; i++)//把輸入的指令遍歷過一次
    {

        if (commands[i] == 'T')
        {
            DetectPath(commands, i);
            i += 2;//讀取進度跳過T後面的兩位數字，已經取好值了
            continue;
        }
        if (commands[i] == 'L')
        {
            //原型宣告Eloop(char* ,int , int)//(指令開頭位址,loop重複幾次(即L後面的個位數字),偏移量)
            i=Eloop(commands, commands[i + 1] - '0', i+1,0);
        }
        

    }

    //    for(int i=0;i<MAXINDEX;i++)
    //    {
    //        printf("%c",commands[i]);
    //    }
    printf("%d", totalPath);
    free(commands);
    system("pause");

}