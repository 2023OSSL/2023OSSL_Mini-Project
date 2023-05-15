// CRUD 기능은 이 파일에 작성해주세요
// 일정에 대한 함수는 Schedule 단어로 표현

#include "CRUD_calendar.h"

int AddSchedule(Schedule *s, char (*tag)[Len_Tag])
{
    int len = 0;
    printf("일정을 추가할 날짜(Date): ");
    scanf("%s", &s->Date[6]);
    getchar(); // 줄바꿈 문자 제거

    system("cls");

    printf("일정 이름: ");
    fgets(s->Name, 12, stdin);
    len = strlen(s->Name)-1;
    s->Name[len] = 0; // 줄바꿈 문자 제거

    system("cls");

    printf("일정에 대한 설명을 작성하시오(20자 이내).\n: ");
    fgets(s->Comment, 42, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    ReadTag(tag);
    printf("추가할 Tag ");
    int Num_Tag = selectDataNo();

    return 1;
}

void ReadTag(char (*tag)[Len_Tag])
{
    for(int i = 0; tag[i][0] != -1; i++){
        printf("[%d] ", i);
        printf("%s\n", tag[i]);
    }
}

int selectDataNo()
{
    int no;
    printf("번호는 (취소: 0)? ");
    scanf("%d", &no);

    return no + 1;
}