/**
 * @file bank_management_system.c
 * @author MRDGH2821 (ask.mrdgh2821@outlook.com)
 * @brief Bank management system made in C
 * @version 0.1
 * @date 2024-05-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
void int_scan(int *number) {
  char s[10] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtol(s, NULL, 10);
}

void lf_scan(double *number) {
  char s[10] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtof(s, NULL);
}

void float_scan(float *number) {
  char s[10] = {};
  fgets(s, sizeof(number), stdin);
  *number = strtof(s, NULL);
}

int i, j;
int main_exit;
void menu();

void close_program() {
  printf("\n\n\nThis C Mini Project is developed by Code With C team!\n");
}

struct date {
  int month, day, year;
};
struct {
  char name[60];
  int acc_no, age;
  char address[60];
  char citizenship[15];
  double phone;
  char acc_type[10];
  float amt;
  struct date dob;
  struct date deposit;
  struct date withdraw;
} add, upd, check, rem, transaction;

float interest(float t, float amount, int rate) {
  float SI;
  SI = (rate * t * amount) / 100.0;
  return (SI);
}

void new_acc() {
  int choice;
  FILE *ptr;
  ptr = fopen("record.dat", "a+");
account_no:
  system("cls");
  printf("\t\t\t\xB2\xB2\xB2 ADD RECORD  \xB2\xB2\xB2\xB2");
  printf("\n\n\nEnter today's date(mm/dd/yyyy):");
  int_scan(&add.deposit.month);
  int_scan(&add.deposit.day);
  int_scan(&add.deposit.year);
  // scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
  printf("\nEnter the account number:");
  int_scan(&check.acc_no);

  while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                &add.acc_no, add.name, &add.dob.month, &add.dob.day,
                &add.dob.year, &add.age, add.address, add.citizenship,
                &add.phone, add.acc_type, &add.amt, &add.deposit.month,
                &add.deposit.day, &add.deposit.year) != EOF) {
    if (check.acc_no == add.acc_no) {
      printf("Account no. already in use!");
      sleep(5);
      goto account_no;
    }
  }

  add.acc_no = check.acc_no;
  printf("\nEnter the name:");
  fgets(add.name, sizeof(add.name), stdin);
  printf("\nEnter the date of birth(mm/dd/yyyy):");
  int_scan(&add.dob.month);
  int_scan(&add.dob.day);
  int_scan(&add.dob.year);
  // scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
  printf("\nEnter the age:");
  int_scan(&add.age);
  printf("\nEnter the address:");
  fgets(add.address, sizeof(add.address), stdin);
  printf("\nEnter the citizenship number:");
  fgets(add.citizenship, sizeof(add.citizenship), stdin);
  printf("\nEnter the phone number: ");
  lf_scan(&add.phone);
  printf("\nEnter the amount to deposit:$");
  float_scan(&add.amt);
  printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 "
         "year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter "
         "your choice:");
  fgets(add.acc_type, sizeof(add.acc_type), stdin);
  fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no,
          add.name, add.dob.month, add.dob.day, add.dob.year, add.age,
          add.address, add.citizenship, add.phone, add.acc_type, add.amt,
          add.deposit.month, add.deposit.day, add.deposit.year);
  fclose(ptr);
  printf("\nAccount created successfully!");
add_invalid:
  printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
  int_scan(&main_exit);
  system("cls");

  if (main_exit == 1) {
    menu();

  } else if (main_exit == 0) {
    close_program();

  } else {
    printf("\nInvalid!\a");
    goto add_invalid;
  }
}

void view_list() {
  FILE *view;
  view = fopen("record.dat", "r");
  int test = 0;
  system("cls");
  printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

  while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no,
                add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age,
                add.address, add.citizenship, &add.phone, add.acc_type,
                &add.amt, &add.deposit.month, &add.deposit.day,
                &add.deposit.year) != EOF) {
    printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address,
           add.phone);
    test++;
  }

  fclose(view);

  if (test == 0) {
    system("cls");
    printf("\nNO RECORDS!!\n");
  }

view_list_invalid:
  printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
  int_scan(&main_exit);
  system("cls");

  if (main_exit == 1) {
    menu();

  } else if (main_exit == 0) {
    close_program();

  } else {
    printf("\nInvalid!\a");
    goto view_list_invalid;
  }
}

void edit(void) {
  int choice, test = 0;
  FILE *old, *newrec;
  old = fopen("record.dat", "r");
  newrec = fopen("new.dat", "w");
  printf(
      "\nEnter the account no. of the customer whose info you want to change:");
  int_scan(&upd.acc_no);

  while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no,
                add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age,
                add.address, add.citizenship, &add.phone, add.acc_type,
                &add.amt, &add.deposit.month, &add.deposit.day,
                &add.deposit.year) != EOF) {
    if (add.acc_no == upd.acc_no) {
      test = 1;
      printf("\nWhich information do you want to "
             "change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address "
             "and 2 for phone):");
      int_scan(&choice);
      system("cls");

      if (choice == 1) {
        printf("Enter the new address:");
        fgets(upd.address, sizeof(upd.address), stdin);
        fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
                add.age, upd.address, add.citizenship, add.phone, add.acc_type,
                add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        system("cls");
        printf("Changes saved!");

      } else if (choice == 2) {
        printf("Enter the new phone number:");
        lf_scan(&upd.phone);
        fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
                add.age, add.address, add.citizenship, upd.phone, add.acc_type,
                add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        system("cls");
        printf("Changes saved!");
      }

    } else {
      fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
              add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
              add.age, add.address, add.citizenship, add.phone, add.acc_type,
              add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
  }

  fclose(old);
  fclose(newrec);
  remove("record.dat");
  rename("new.dat", "record.dat");

  if (test != 1) {
    system("cls");
    printf("\nRecord not found!!\a\a\a");
  edit_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    int_scan(&main_exit);
    system("cls");

    if (main_exit == 1) {
      menu();

    } else if (main_exit == 2) {
      close_program();

    } else if (main_exit == 0) {
      edit();

    } else {
      printf("\nInvalid!\a");
      goto edit_invalid;
    }

  } else {
    printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    int_scan(&main_exit);
    system("cls");

    if (main_exit == 1) {
      menu();

    } else {
      close_program();
    }
  }
}

void transact(void) {
  int choice, test = 0;
  FILE *old, *newrec;
  old = fopen("record.dat", "r");
  newrec = fopen("new.dat", "w");
  printf("Enter the account no. of the customer:");
  int_scan(&transaction.acc_no);

  while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no,
                add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age,
                add.address, add.citizenship, &add.phone, add.acc_type,
                &add.amt, &add.deposit.month, &add.deposit.day,
                &add.deposit.year) != EOF) {
    if (add.acc_no == transaction.acc_no) {
      test = 1;

      if ((strcasecmp(add.acc_type, "fixed1") == 0) ||
          (strcasecmp(add.acc_type, "fixed2") == 0) ||
          (strcasecmp(add.acc_type, "fixed3") == 0)) {
        printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED "
               "ACCOUNTS!!!!!");
        sleep(5);
        system("cls");
        menu();
      }

      printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your "
             "choice(1 for deposit and 2 for withdraw):");
      int_scan(&choice);

      if (choice == 1) {
        printf("Enter the amount you want to deposit:$ ");
        float_scan(&transaction.amt);
        add.amt += transaction.amt;
        fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
                add.age, add.address, add.citizenship, add.phone, add.acc_type,
                add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        printf("\n\nDeposited successfully!");

      } else {
        printf("Enter the amount you want to withdraw:$ ");
        float_scan(&transaction.amt);
        add.amt -= transaction.amt;
        fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
                add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
                add.age, add.address, add.citizenship, add.phone, add.acc_type,
                add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
        printf("\n\nWithdrawn successfully!");
      }

    } else {
      fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
              add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
              add.age, add.address, add.citizenship, add.phone, add.acc_type,
              add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
    }
  }

  fclose(old);
  fclose(newrec);
  remove("record.dat");
  rename("new.dat", "record.dat");

  if (test != 1) {
    printf("\n\nRecord not found!!");
  transact_invalid:
    printf(
        "\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    int_scan(&main_exit);
    system("cls");

    if (main_exit == 0) {
      transact();

    } else if (main_exit == 1) {
      menu();

    } else if (main_exit == 2) {
      close_program();

    } else {
      printf("\nInvalid!");
      goto transact_invalid;
    }

  } else {
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
    int_scan(&main_exit);
    system("cls");

    if (main_exit == 1) {
      menu();

    } else {
      close_program();
    }
  }
}

void erase(void) {
  FILE *old, *newrec;
  int test = 0;
  old = fopen("record.dat", "r");
  newrec = fopen("new.dat", "w");
  printf("Enter the account no. of the customer you want to delete:");
  int_scan(&rem.acc_no);

  while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no,
                add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age,
                add.address, add.citizenship, &add.phone, add.acc_type,
                &add.amt, &add.deposit.month, &add.deposit.day,
                &add.deposit.year) != EOF) {
    if (add.acc_no != rem.acc_no) {
      fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
              add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
              add.age, add.address, add.citizenship, add.phone, add.acc_type,
              add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

    } else {
      test++;
      printf("\nRecord deleted successfully!\n");
    }
  }

  fclose(old);
  fclose(newrec);
  remove("record.dat");
  rename("new.dat", "record.dat");

  if (test == 0) {
    printf("\nRecord not found!!\a\a\a");
  erase_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    int_scan(&main_exit);

    if (main_exit == 1) {
      menu();

    } else if (main_exit == 2) {
      close_program();

    } else if (main_exit == 0) {
      erase();

    } else {
      printf("\nInvalid!\a");
      goto erase_invalid;
    }

  } else {
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
    int_scan(&main_exit);
    system("cls");

    if (main_exit == 1) {
      menu();

    } else {
      close_program();
    }
  }
}

void see(void) {
  FILE *ptr;
  int test = 0, rate;
  int choice;
  float time;
  float intrst;
  ptr = fopen("record.dat", "r");
  printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
  int_scan(&choice);

  if (choice == 1) {
    printf("Enter the account number:");
    int_scan(&check.acc_no);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
                  &add.acc_no, add.name, &add.dob.month, &add.dob.day,
                  &add.dob.year, &add.age, add.address, add.citizenship,
                  &add.phone, add.acc_type, &add.amt, &add.deposit.month,
                  &add.deposit.day, &add.deposit.year) != EOF) {
      if (add.acc_no == check.acc_no) {
        system("cls");
        test = 1;
        printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s "
               "\nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s "
               "\nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",
               add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
               add.age, add.address, add.citizenship, add.phone, add.acc_type,
               add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        if (strcasecmp(add.acc_type, "fixed1") == 0) {
          time = 1.0;
          rate = 9;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $%.2f as interest on %d/%d/%d", intrst,
                 add.deposit.month, add.deposit.day, add.deposit.year + 1);

        } else if (strcasecmp(add.acc_type, "fixed2") == 0) {
          time = 2.0;
          rate = 11;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst,
                 add.deposit.month, add.deposit.day, add.deposit.year + 2);

        } else if (strcasecmp(add.acc_type, "fixed3") == 0) {
          time = 3.0;
          rate = 13;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst,
                 add.deposit.month, add.deposit.day, add.deposit.year + 3);

        } else if (strcasecmp(add.acc_type, "saving") == 0) {
          time = (1.0 / 12.0);
          rate = 8;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d of every month",
                 intrst, add.deposit.day);

        } else if (strcasecmp(add.acc_type, "current") == 0) {
          printf("\n\nYou will get no interest\a\a");
        }
      }
    }

  } else if (choice == 2) {
    printf("Enter the name:");
    fgets(check.name, sizeof(check.name), stdin);

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
                  &add.acc_no, add.name, &add.dob.month, &add.dob.day,
                  &add.dob.year, &add.age, add.address, add.citizenship,
                  &add.phone, add.acc_type, &add.amt, &add.deposit.month,
                  &add.deposit.day, &add.deposit.year) != EOF) {
      if (strcasecmp(add.name, check.name) == 0) {
        system("cls");
        test = 1;
        printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s "
               "\nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s "
               "\nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",
               add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
               add.age, add.address, add.citizenship, add.phone, add.acc_type,
               add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

        if (strcasecmp(add.acc_type, "fixed1") == 0) {
          time = 1.0;
          rate = 9;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst,
                 add.deposit.month, add.deposit.day, add.deposit.year + 1);

        } else if (strcasecmp(add.acc_type, "fixed2") == 0) {
          time = 2.0;
          rate = 11;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst,
                 add.deposit.month, add.deposit.day, add.deposit.year + 2);

        } else if (strcasecmp(add.acc_type, "fixed3") == 0) {
          time = 3.0;
          rate = 13;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d/%d/%d", intrst,
                 add.deposit.month, add.deposit.day, add.deposit.year + 3);

        } else if (strcasecmp(add.acc_type, "saving") == 0) {
          time = (1.0 / 12.0);
          rate = 8;
          intrst = interest(time, add.amt, rate);
          printf("\n\nYou will get $.%.2f as interest on %d of every month",
                 intrst, add.deposit.day);

        } else if (strcasecmp(add.acc_type, "current") == 0) {
          printf("\n\nYou will get no interest\a\a");
        }
      }
    }
  }

  fclose(ptr);

  if (test != 1) {
    system("cls");
    printf("\nRecord not found!!\a\a\a");
  see_invalid:
    printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
    int_scan(&main_exit);
    system("cls");

    if (main_exit == 1) {
      menu();

    } else if (main_exit == 2) {
      close_program();

    } else if (main_exit == 0) {
      see();

    } else {
      system("cls");
      printf("\nInvalid!\a");
      goto see_invalid;
    }

  } else {
    printf("\nEnter 1 to go to the main menu and 0 to exit:");
    int_scan(&main_exit);
  }

  if (main_exit == 1) {
    system("cls");
    menu();

  } else {
    system("cls");
    close_program();
  }
}

void menu(void) {
  int choice;
  system("cls");
  system("color 9");
  printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
  printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU "
         "\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
  printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing "
         "account\n\t\t3.For transactions\n\t\t4.Check the details of existing "
         "account\n\t\t5.Removing existing account\n\t\t6.View customer's "
         "list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
  int_scan(&choice);
  system("cls");

  switch (choice) {
  case 1:
    new_acc();
    break;

  case 2:
    edit();
    break;

  case 3:
    transact();
    break;

  case 4:
    see();
    break;

  case 5:
    erase();
    break;

  case 6:
    view_list();
    break;

  case 7:
    close_program();
    break;
  }
}

bool is_string_equal(char *str1, char *str2) {
  int i = 0;

  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return false;
    }

    i++;
  }

  return true;
}

int main() {
  char pass[15], password[15] = "projectnotes";
  int i = 0;
  printf("\n\n\t\tEnter the password to login:");
  fgets(pass, sizeof(pass), stdin);

  if (is_string_equal(pass, password)) {
    printf("\n\nPassword Match!\nLOADING");

    for (i = 0; i <= 6; i++) {
      sleep(1);
      printf(".");
    }

    system("cls");
    menu();

  } else {
    printf("\n\nWrong password!!\a\a\a");
  login_try:
    printf("\nEnter 1 to try again and 0 to exit:");
    int_scan(&main_exit);

    if (main_exit == 1) {
      system("cls");
      main();

    } else if (main_exit == 0) {
      system("cls");
      close_program();

    } else {
      printf("\nInvalid!");
      sleep(5);
      system("cls");
      goto login_try;
    }
  }

  return 0;
}
