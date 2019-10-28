#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
void MOVE(int num, char Beg, char Aux, char End)
{
    if (num == 1)
    {
        printf("step %2d : Disk 1 from %c---->%c\n",++cnt, Beg, End);
        return;
    }
    MOVE(num - 1, Beg, End, Aux);
    printf("step %2d : Disk %d from %c---->%c\n",++cnt, num, Beg, End);
    MOVE(num - 1, Aux, Beg, End);
}

int main()
{
    int num;

    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The Steps are:\n");
    MOVE(num, 'A', 'B', 'C');
    return 0;
}
