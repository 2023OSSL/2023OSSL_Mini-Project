// CRUD 기능은 이 파일에 작성해주세요
// 일정에 대한 함수는 Schedule 단어로 표현

#include "./CRUD_calendar.h"


// CRUD Functions
void ReadSchedule()
{

}

int AddSchedule(Schedule *s, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("일정을 추가할 날짜(Date): ");
    scanf("%d", &s->Time_Info.tm_mday);
    getchar(); // 개행 문자 제거

    system("cls");

    printf("일정 이름: ");
    fgets(s->Name, 12, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // 개행 문자 제거

    system("cls");

    printf("일정에 대한 설명을 작성하시오(20자 이내).\n: ");
    fgets(s->Comment, 62, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    return 1;
}

// int UpdateSchedule(){}

void ReadTag(char (*tag)[Len_Tag], int count)
{
    for(int i = 0; i < count; i++){
        printf("[%d] ", i);
        printf("%s\n", tag[i]);
    }
}

int AddTag(char (*tag)[Len_Tag], int count)
{
    if(count == 10){
        printf("** 더이상 태그를 추가할 수 없습니다 **");
        return count;
    }

    ReadTag(tag, count);
    putchar('\n');

    printf("추가할 태그명 (공백없이 입력, 최대 10개): ");
    scanf("%s", tag[count]);

    return count + 1;
}

int selectDataNo()
{
    int no;
    printf("번호는 (취소: 0)? ");
    scanf("%d", &no);

    return no + 1;
}


// File IO Functions
int SaveData(Schedule *s[], int count)
{
    FILE *fp;
    char filename[16];

    for(int i = 0; i < count; i++){
        sprintf(filename, "%4d%02d%02d.txt",
            s[i]->Time_Info.tm_year + 1900,
            s[i]->Time_Info.tm_mon + 1,
            s[i]->Time_Info.tm_mday);

        fp = fopen(filename, "at");
        fputs(s[i]->Name, fp);
        fputs("\n", fp);
        fputs(s[i]->Comment, fp);
        fputs("\n", fp);

        fp = fopen("filedata.txt", "at");
        fputs(filename, fp);

        fclose(fp);
    }
}

// int LoadData(){}