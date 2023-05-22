// CRUD ����� �� ���Ͽ� �ۼ����ּ���
// ������ ���� �Լ����� "Schedule" �ܾ �����Ͽ� �ۼ�

#include "./CRUD_calendar.h"


// CRUD Functions
int AddSchedule(Schedule *s, int count, char (*tag)[Len_Tag])
{
    int len;

    system("cls");

    printf("���� �̸�: ");
    fgets(s->Name, Len_Name, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // ���� ���� ����

    system("cls");

    printf("������ ���� ������ �ۼ��Ͻÿ�(20�� �̳�)\n: ");
    fgets(s->Comment, Len_Comment, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    s->Complete = 0;

    system("cls");

    int no = 0;

    system("cls");

    ReadTag(tag);
    printf("�±� ���� >> ");
    scanf("%d", &no);
    getchar();

    sprintf(s->Tag, "%s", tag[no-1]);

    return 1;
}

void ReadSchedule(Schedule *s)
{
    printf("| %s     | #%s     | %s |\n", s->Name, s->Tag, s->Complete ? "O" : "X");
}

void ListSchedule(Schedule *s[], Time t, int index)
{
    int count = 1;
    printf("=====================================\n");
    printf(" No | �����̸� | �±�    | �ϷῩ�� |\n");
    printf("=====================================\n");
    
    for(int i = 0; i < index; i++){
        if(s[i]->Name[0] == -1) continue;
        
        if((t.tm_mon == s[i]->Time_Info.tm_mon) && (t.tm_mday == s[i]->Time_Info.tm_mday)){
            printf(" %2d ", count);
            ReadSchedule(s[i]);
            count++;
        } else
            continue;
    }

    putchar('\n');
}

int UpdateSchedule(Schedule *s, int count, char (*tag)[Len_Tag])
{
    int len = 0;

    system("cls");

    printf("���� �̸�: ");
    fgets(s->Name, Len_Name, stdin);
    len = strlen(s->Name) - 1;
    s->Name[len] = 0; // ���� ���� ����

    system("cls");

    printf("������ ���� ������ �ۼ��Ͻÿ�(20�� �̳�).\n: ");
    fgets(s->Comment, Len_Comment, stdin);
    len = strlen(s->Comment)-1;
    s->Comment[len] = 0;

    system("cls");

    int no = 0;

    ReadTag(tag);
    printf("�±� ���� >> ");
    scanf("%d", &no);

    sprintf(s->Tag, "%s", tag[no]);

    return 1;
}

// DeleteSchedule(){}


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
        printf("** ���̻� �±׸� �߰��� �� �����ϴ� **");
        return count;
    }

    ReadTag(tag);
    putchar('\n');

    printf("�߰��� �±׸� (5�� �̳�, ������� �Է�, �ִ� 10��): ");
    scanf("%s", tag[count]);

    return 1;
}

int selectDataNo()
{
    int no;
    printf("��ȣ�� (���: 0)? ");
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

    printf("** ����Ϸ�");

    fclose(fp);
    return 1;
}

int LoadData(Schedule *s[])
{
    int count = 0, i = 0, len = 0;
    FILE *fp = fopen(DataFile, "rt");
    time_t t;

    if(fp == NULL){
        printf("** �ε� ���� **\n");
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

    if(count != 0) printf("** �ε����� **\n");
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

void SearchData(Schedule *s[], int count, char (*tag)[Len_Tag]) {
    int menu;
    system("cls");
    
    printf("** �±� ��� **\n");
    ReadTag(tag);
    printf("***************\n");
    
    printf("�˻��� �±� ��ȣ (0: ���) >> ");
    scanf("%d", &menu);
    
    if (menu == 0) {
        printf(">> �˻��� ��ҵǾ����ϴ�.\n");
        return;
    }
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(s[i]->Tag, tag[menu - 1]) == 0) {
            ReadSchedule(s[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf(">> �ش� �±׿� �ش��ϴ� ������ �����ϴ�.\n");
    }
}