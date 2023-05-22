// CRUD 기능은 이 파일에 작성해주세요
// 일정에 대한 함수는 Schedule 단어로 표현

#include "./CRUD_calendar.h"


// CRUD Functions
void ReadSchedule(Schedule *s)
{
    printf("");
}

int AddSchedule(Schedule *s, int count, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("일정을 추가할 날짜(Date): ");
    scanf("%d", &s->Time_Info.tm_mday);
    getchar(); // 개행 문자 제거

    system("cls");

    printf("일정 이름: ");
    fgets(s->Name, Len_Name, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // 개행 문자 제거

    system("cls");

    printf("일정에 대한 설명을 작성하시오(20자 이내).\n: ");
    fgets(s->Comment, Len_Comment, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    int no = 0;

    ReadTag(tag);
    printf("태그 선택 >> ");
    scanf("%d", &no);

    sprintf(s->Tag, "%s", tag[no]);

    return 1;
}

int UpdateSchedule(Schedule *s, int count, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("일정을 수정할 날짜(Date): ");
    scanf("%d", &s->Time_Info.tm_mday);
    getchar(); // 개행 문자 제거

    system("cls");

    printf("일정 이름: ");
    fgets(s->Name, Len_Name, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // 개행 문자 제거

    system("cls");

    printf("일정에 대한 설명을 작성하시오(20자 이내).\n: ");
    fgets(s->Comment, Len_Comment, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    int no = 0;

    ReadTag(tag);
    printf("태그 선택 >> ");
    scanf("%d", &no);

    sprintf(s->Tag, "%s", tag[no]);

    return 1;
}

void ReadTag(char (*tag)[Len_Tag])
{
    for(int i = 0; i < 10; i++){
        if(tag[i][0] == 0)
            break;
        
        printf("[%d] ", i+1);
        printf("%s\n", tag[i]);
    }
}

int AddTag(char (*tag)[Len_Tag], int count)
{
    if(count == 10){
        printf("** 더이상 태그를 추가할 수 없습니다 **");
        return count;
    }

    ReadTag(tag);
    putchar('\n');

    printf("추가할 태그명 (공백없이 입력, 최대 10개): ");
    scanf("%s", tag[count]);

    return 1;
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
    FILE *fp = fopen(DataFile, "wt");
    time_t t;

    for(int i = 0; i < count; i++){
        t = mktime(&s[i]->Time_Info);
        fprintf(fp, "%d\n", t);
        fputs(s[i]->Name, fp); fputs("\n", fp);
        fputs(s[i]->Comment, fp); fputs("\n", fp);
        fputs(s[i]->Tag, fp); fputs("\n", fp);
        fprintf(fp, "%d\n", s[i]->Complete);
    }

    fclose(fp);
    return 1;
}

int LoadData(Schedule *s[])
{
    int count = 0, i = 0;
    FILE *fp = fopen(DataFile, "rt");
    time_t t;

    if(fp == NULL){
        printf("** 로딩 실패 **");
        return 0;
    }

    for(i = 0; i < NData; i++){
        s[i] = (Schedule *)malloc(sizeof(Schedule));
        
        fscanf(fp, "%d\n", &t);
        s[i]->Time_Info = *localtime(&t);
        fgets(s[i]->Name, Len_Name, fp);
        fgets(s[i]->Comment, Len_Comment, fp);
        fgets(s[i]->Tag, Len_Tag, fp);
        fscanf(fp, "%d\n", &s[i]->Complete);

        count++;
    }

    fclose(fp);

    if(count != 0) printf("** 로딩성공 **\n");
    return count;
}