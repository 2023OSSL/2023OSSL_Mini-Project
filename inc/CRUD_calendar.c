// CRUD 기능은 이 파일에 작성해주세요
// 일정에 대한 함수명은 "Schedule" 단어를 포함하여 작성

#include "./CRUD_calendar.h"


// CRUD Functions
int AddSchedule(Schedule *s, char (*tag)[Len_Tag])
{
    int len;

    system("cls");

    printf("일정 이름: ");
    fgets(s->Name, Len_Name, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // 개행 문자 제거

    system("cls");

    printf("일정에 대한 설명을 작성하시오(20자 이내)\n: ");
    fgets(s->Comment, Len_Comment, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    s->Complete = 0;

    system("cls");

    int no = 0;

    system("cls");

    ReadTag(tag);
    printf("태그 선택 >> ");
    scanf("%d", &no);
    getchar();

    sprintf(s->Tag, "%s", tag[no-1]);

    return 1;
}

void ReadSchedule(Schedule *s) {
    printf("| %s     | #%s     | %c |\n", s->Name, s->Tag, s->Complete);
}

void ListSchedule(Schedule *s[], Time t, int index)
{
    int count = 1;
    printf("=====================================\n");
    printf(" No | 일정이름 | 태그    | 완료여부 |\n");
    printf("=====================================\n");
    
    for(int i = 0; i < index; i++){
        if(s[i]->Name[0] == -1) continue;
        
        if((t.tm_mday == s[i]->Time_Info.tm_mday)&&(t.tm_mday == s[i]->Time_Info.tm_mday)){
            printf(" %2d ", count);
            ReadSchedule(s[i]);
            count++;
        } else
            continue;
    }

    putchar('\n');
}

int UpdateSchedule(Schedule *s, char (*tag)[Len_Tag])
{
    int len = 0;

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
    getchar();

    sprintf(s->Tag, "%s", tag[no-1]);

    return 1;
}

// Tag Functions
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

    printf("추가할 태그명 (5자 이내, 공백없이 입력, 최대 10개): ");
    scanf("%s", tag[count]);
    getchar();

    return 1;
}

void SaveTag(char (*tag)[Len_Tag], int t_count)
{
    FILE *fp = fopen(TagDataFile, "wt");

    for(int i = 0; i < t_count; i++)
        fprintf(fp, "%s\n", tag[i]);
}

int LoadTag(char (*tag)[Len_Tag])
{
    FILE *fp = fopen(TagDataFile, "rt");
    int count = 0;
    char temp[Len_Tag];

    if(fp == NULL) return 0;

    for(int i = 0; i < 10; i++){
        fgets(temp, Len_Tag, fp);
        int len = strlen(temp)-1;
        temp[len] = 0;
        if(feof(fp)) break;
        sprintf(tag[i], "%s", temp);
        count++;
    }

    return count;
}

int selectDataNo()
{
    int no;
    printf("번호는 (취소: 0)? ");
    scanf("%d", &no);
    getchar();

    return no;
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

    printf("** 저장완료");

    fclose(fp);
    return 1;
}

int LoadData(Schedule *s[])
{
    int count = 0, i = 0, len = 0;
    FILE *fp = fopen(DataFile, "rt");
    time_t t;

    if(fp == NULL){
        printf("** 로딩 실패 **\n");
        return 0;
    }

    for(i = 0; i < NData; i++){
        s[i] = (Schedule *)malloc(sizeof(Schedule));
        
        fscanf(fp, "%d\n", &t);

        if(feof(fp)) break;

        s[i]->Time_Info = *localtime(&t);
        fgets(s[i]->Name, Len_Name, fp);
        fgets(s[i]->Comment, Len_Comment, fp);
        fgets(s[i]->Tag, Len_Tag, fp);
        fscanf(fp, "%d\n", &s[i]->Complete);

        len = strlen(s[i]->Name) - 1;
        s[i]->Name[len] = 0;
        len = strlen(s[i]->Comment)-1;
        s[i]->Comment[len] = 0;
        len = strlen(s[i]->Tag)-1;
        s[i]->Tag[len] = 0;

        count++;
    }

    fclose(fp);

    if(count != 0) printf("** 로딩성공 **\n");
    return count;
}

void AlertUser(Schedule *s[], int count)
{
    time_t currentTime;
    time(&currentTime);
    Time current = *localtime(&currentTime);
  
    for (int i = 0; i < count; i++) {
        Schedule *schedule = s[i];
        if (schedule->Time_Info.tm_mday == current.tm_mday &&
            schedule->Time_Info.tm_mon == current.tm_mon &&
            schedule->Time_Info.tm_year == current.tm_year) {
            printf("ALERT! : %s (%s) %d/%d\n", schedule->Name, schedule->Comment, schedule->Time_Info.tm_mon + 1, schedule->Time_Info.tm_mday);
        }
    }
}

void SearchData(Schedule *s[], int count, char (*tag)[Len_Tag], int tagNo) {
    int found = 0;

    printf("\n%s 태그에 해당하는 일정 목록:\n", tag[tagNo - 1]);
    for (int i = 0; i < count; i++) {
        if (strcmp(s[i]->Tag, tag[tagNo - 1]) == 0) {
            ReadSchedule(s[i]);
            found = 1;
        }
    }

    if (!found) {
        printf(">> 해당 태그에 해당하는 일정은 없습니다.\n");
    }
}

void ScheduleComplete(Schedule *s[], int count) {
    time_t currentTime;
    time(&currentTime);
    Time current = *localtime(&currentTime);
  
    for (int i = 0; i < count; i++) {
        Schedule *schedule = s[i];
        time_t scheduleTime = mktime(&schedule->Time_Info);

        if (difftime(currentTime, scheduleTime) > 0) {
            schedule->Complete = 'O';
        } else {
            schedule->Complete = 'X';
        }
    }
}

int DeleteSchedule(Schedule *s[], int count, char (*tag)[Len_Tag], Time selectedDate, int selectedScheduleNo)
{
    int deletedIndex = 0;
    for (int i = 0; i < count; i++) {
        if (s[i]->Time_Info.tm_mon == selectedDate.tm_mon && s[i]->Time_Info.tm_mday == selectedDate.tm_mday) {
            deletedIndex++;
            if (deletedIndex == selectedScheduleNo) {
                free(s[i]);
                for (int j = i; j < count - 1; j++) {
                    s[j] = s[j + 1];
                }
                s[count - 1] = NULL;
                printf(">> 일정이 삭제되었습니다.\n");
                return 1;
            }
        }
    }

    printf(">> 일정 삭제에 실패했습니다.\n");
    return 0;
}

