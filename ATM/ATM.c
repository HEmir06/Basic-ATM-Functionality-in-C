/* Project Name is 'Basic ATM Functionality in C'*/
#include<stdio.h>
#include <string.h>
// Global variable for balance initialization
int bakiye=1000; // initial balance one thousand for everyone.

void sifreilk () //function create
{
    char ilksifre[20];// Array to store the new password
    int i ;
    printf(" Yeni sifre olusturunuz (sadece rakam kullanınız)");// Ask the user to create a password
    scanf("%s",&ilksifre);// Take input for password
        for(i = 0; ilksifre[i] != '\0'; i++) // Loop to check each character of the password
            {
        if(ilksifre[i] < '0' || ilksifre[i] > '9') // Check if the character is not a digit
        {
            printf("Hatalı şifre! Şifre yalnızca rakamlardan oluşmalıdır.\n");// Error if non-numeric character is found
            return 0 ;// Exit the function

        }
    }
    printf ("Sifreniz:%s lütfen unutmayiniz. \n",ilksifre[20]);// Print the password (incorrect usage of array)
}

int bilgiler(int islem) //function create
{
    int giris, cikis;

    switch (islem) // Switch statement to handle different operations
    {
        case 1:// Case 1: Check Balance

            printf("Bakiyeniz: %d\n", bakiye); // Display the current balance
            break;

        case 2:// Case 2: Deposit Money

            printf("Yatirmak istediginiz tutari giriniz: ");// Ask the user to input the deposit amount
            scanf("%d", &giris);// Take the deposit amount as input
            bakiye += giris;// Add the deposit amount to the balance
            printf("Yeni Bakiyeniz: %d\n", bakiye);// Display the new balance
            break;

        case 3:// Case 3: Withdraw Money

            printf("Cekmek istediginiz tutari giriniz: ");// Ask the user to input the withdrawal amount
            scanf("%d", &cikis);// Take the withdrawal amount as input
              if (cikis > bakiye) // Check if the withdrawal amount exceeds the balance
              {
                printf("Yetersiz bakiye!\n");// Error message if insufficient balance
              }
                else
                {
                    bakiye -= cikis;// Subtract the withdrawal amount from the balance
                    printf("Yeni Bakiyeniz: %d\n", bakiye);// Display the new balance
                }
        break;

        case 4:// Case 4: Change Password

            sifreilk();// Call the password change function
            break;

        default:// Default case for invalid operations

            printf("Gecersiz islem.\n");// Error message for invalid operation
            break;

    }

    return bakiye;// Return the updated balance

}
    int main ()
{
      int sifre,islem,sonislem=1,yenisif;
      char girilenSifre[20]="1234";// Default password is set to "1234"
      printf("*** Welcome ***\n");
      printf("Þifrenizi Giriniz Eger Kart iadesi istiyorsanız 1 tuşlayınız yoksa herhangi bir rakamı tuşlayınız");
       // Ask the user to enter a password or press 1 for card return
      scanf("%s",&yenisif); // Take input for new password or card return
        if(yenisif==1)// If the user presses 1, the program ends
            {
            return 0;
            }

         else
        {
          printf("şifrenizi giriniz");// Ask the user to input the password
          scanf("%s",&girilenSifre);// Take the input password

            if (strcmp(girilenSifre, "1234") == 0)// Check if the entered password matches the default password "1234"
            {

                do{
                    // Show the transaction options menu
                    printf("Hangi iþlemi yapmak istiyorsunuz");
                    printf("1:Bakiye Ögrenme\n");//Balance Learning
                    printf("2:Para Yatirma\n");//Deposit
                    printf("3:Para Çekme\n");//Withdraw money
                    printf("4:Şifre Degiþtirme\n");// Change password
                    printf("Hangi islemi yapcaksaniz onu tuslayiniz");
                    scanf("%d",&islem);// Take the transaction type as input
                    bakiye = bilgiler(islem); // Call the 'bilgiler' function to perform the selected operation
                    printf("Son durumdaki bakiyeniz: %d\n", bakiye);// Display the updated balance
                    printf (" İşlem Yapmaya Devam Edicekmisiniz ");
                    printf("İşlem yapmaya devam etmek istiyor musunuz?\n");// Ask if the user wants to continue or exit the system
                    printf("1: Evet\n");//1:Yes
                    printf("2: Hayır\n");//2:No
                    scanf("%d", &sonislem);

                if (sonislem != 1 && sonislem != 2) // If invalid input is given, the program exits
                {
                    printf("Hatalı giriş yaptınız!\n");
                    return 0;
                        }
                }
                    while (sonislem == 1);// If user selects "Yes" (1), the loop continues

                        if(sonislem==2) // If user selects "No" (2), exit the program
                            {
                        printf ("Bizi Kullandıgınız için teşekkür ederiz");// Display thank you message
                            }
            }
                            else // If the entered password is incorrect
                            {
                                printf("Hatali şifre girmişssiniz");// Error message for incorrect password
                            }
        }

    return 0;// End the program
}
