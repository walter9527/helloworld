#include "common.h"

typedef struct node {
    int num;
    char name[32];
    float scoce;
    struct node *next;
} STU;

STU *head = NULL;
STU dummy = {-1, "", 0, NULL};

int size = 0;

STU *get_dummy() {
    dummy.next = head;
    return &dummy;
}

int get_size() {
    return size;
}

// 创建节点
STU *get_node(int num, const char *name, float score) {
    STU *stu = calloc(1, sizeof(STU));
    is_get_mem(stu);

    stu->num = num;
    strcpy(stu->name, name);
    stu->scoce = score;
    stu->next = NULL;
    return stu;
}

// 按编号查找前节点
STU *find_num_pre(const int num) {
    STU *tmp = get_dummy();
    while (tmp->next != NULL && tmp->next->num < num) {
        tmp = tmp->next;
    }

    return tmp;
}

// 按编号查找
STU *find_num(const int num) {
    STU *pre = find_num_pre(num);

    return pre->next == NULL || pre->next->num > num ? NULL : pre->next;
}

// 添加节点
STU *add(int num, const char *name, short age) {
    STU *node = get_node(num, name, age);

    STU *pre = find_num_pre(num);

    if (head == NULL) {
        head = node;
    } else {
        node->next = pre->next;
        pre->next = node;
    }

    size++;
    return node;
}

// 按姓名搜索
STU *find_name(const char *name) {
    STU *tmp = head;

    while (tmp != NULL && strcmp(tmp->name, name) != 0) {
        tmp = tmp->next;
    }

    return tmp;
}

// 按编号删除节点
void remove_node_num(int num) {
    STU *pre = find_num_pre(num);
    STU *cur = pre->next == NULL || pre->next->num > num ? NULL : pre->next;
    if (cur != NULL) {
        pre->next = cur->next;
        free(cur);
        size++;
    }
}

// 按姓名删除节点
void remove_node_name(const char *name) {
    STU *tmp = get_dummy();
    while (tmp->next != NULL && strcmp(tmp->next->name, name) != 0) {
        tmp = tmp->next;
    }
    STU *res = tmp->next;
    if (res != NULL) {
        tmp->next = res->next;
        free(res);
        size--;
    }
}

// 删除所有
void remove_all() {
    for (STU *stu = head; stu != NULL;) {
        STU *next = stu->next;
        free(stu);
        stu = next;
    }
    head = NULL;
    size = 0;
}


void print(STU *stu) {
    if (stu != NULL) {
        printf("num = %d, name = %s, score = %f\n", stu->num, stu->name, stu->scoce);
    }
}

// 遍历打印
void linked_list_print() {
    for (STU *s = head; s != NULL; s = s->next) {
        print(s);
    }
}

// 链表的逆序
void decend(STU *cur) {
    if (cur == NULL || cur->next == NULL) {
        head = cur;
        return;
    }
    STU *next = cur->next;
    if (next->next != NULL || !(head = NULL)) {
        decend(next);
    }
    next->next = cur;
    cur->next = NULL;
    head = head == NULL ? next : head;
}

void decend_iter() {
    if (head == NULL) {
        return;
    }
    STU *next = head->next;
    head->next = NULL;
    STU *pro = NULL;
    while (next != NULL) {
        pro = next->next;

        next->next = head;

        head = next;
        next = pro;
    }

}

void select_sort() {
    STU *tmp2 = NULL;
    STU *newhead = head;
    STU *newtail = NULL;
    while (head != NULL) {
        STU *min = get_dummy();
        for (STU *cur = head; cur->next != NULL; cur = cur->next) {
            if (cur->next->scoce < min->next->scoce) {
                min = cur;
            }
        }
        STU *curmin = min->next;
        if (min == get_dummy()) {
            head = head->next;
        } else {
            min->next = curmin->next;
        }
        curmin->next = NULL;
        if (newtail == NULL) {
            newtail = curmin;
        } else {
            newtail->next = curmin;
        }
        newhead = curmin;
    }
    head = newhead;
}

int main(int argc, char *argv[]) {
    add(10, "clinton", 30);
    add(20, "bush", 40);
//   add(30, "obama", 50);
    add(40, "trump", 60);
    add(51, "biden", 80);
    add(35, "linclon", 70);

    printf("size = %d\n", get_size());
    linked_list_print();

    split_line();

    STU *stu = find_name("joe");
    print(stu);

    split_line();
//    remove_node_num(40);
    remove_node_name("obama");

    linked_list_print();

    printf("get_size() = %d\n", get_size());

//    split_line();
//
//    remove_all();
//
//    linked_list_print();
//
//    printf("size = %d\n", size);

    stu = find_num(50);
    print(stu);
    split_line();
//    decend(head);
    decend_iter();
    linked_list_print();

    split_line();
    select_sort();
    linked_list_print();
    return 0;
}

