import java.util.*;

public class Aa {

    public static void main(String[] args) {

        int year, month, day;

        int days = 0;

        int d = 0;

        int e;

        input fymd = new input();

        do {

            e = 0;

            System.out.print("�����꣺");

            year =fymd.input();

            System.out.print("�����£�");

            month = fymd.input();

            System.out.print("�����죺");

            day = fymd.input();

            if (year < 0 || month < 0 || month > 12 ||day < 0 || day > 31) {

                System.out.println("����������������룡");

                e=1 ;

            }

        }while( e==1);

 

        for (int i=1; i <month; i++) {

            switch (i) {

                case 1:

                case 3:

                case 5:

                case 7:

                case 8:

                case 10:

                case 12:

                    days = 31;

                    break;

                case 4:

                case 6:

                case 9:

                case 11:

                    days = 30;

                    break;

                case 2:

                    if ((year % 400 == 0) || (year % 4 == 0&& year % 100 != 0)) {

                        days = 29;

                    } else {

                        days = 28;

                    }

                    break;

            }

            d += days;

        }

        System.out.println(year + "-" + month +"-" + day + "������ĵ�" +(d+day) + "�졣");

        }

    }

 

class input{

    public int input() {

        int value = 0;

        Scanner s = new Scanner(System.in);

        value = s.nextInt();

        return value;

    }

}
