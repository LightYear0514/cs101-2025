#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int age;
    double salary;
    char name[50];
} employee_t;

// 顯示員工資訊
void emp_info(employee_t emp) {
    printf("Employee ID: %d\n", emp.id);
    printf("Employee Name: %s\n", emp.name);
    printf("Employee Age: %d\n", emp.age);
    printf("Employee Salary: %.2f\n", emp.salary);
    printf("-------------------------\n");
}

// 將員工資料寫入二進位檔案
void emp_writefile(employee_t emp[], int n) {
    FILE *file = fopen("employee.bin", "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    fwrite(emp, sizeof(employee_t), n, file);
    fclose(file);
}

// 從二進位檔案讀取員工資料
void emp_readfile(employee_t emp[], int n) {
    FILE *file = fopen("employee.bin", "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    fread(emp, sizeof(employee_t), n, file);
    fclose(file);
}

int main() {
    // 初始化員工資料
    employee_t emp[3] = {
        {1, 20, 30000.0, "IU"},
        {2, 26, 36000.0, "Taylor"},
        {3, 31, 90000.0, "Swift"}
    };

    // 寫入檔案
    emp_writefile(emp, 3);

    // 讀取檔案資料
    employee_t read_emp[3];
    emp_readfile(read_emp, 3);

    // 輸出至螢幕
    for (int i = 0; i < 3; i++) {
        emp_info(read_emp[i]);
    }

    return 0;
}
