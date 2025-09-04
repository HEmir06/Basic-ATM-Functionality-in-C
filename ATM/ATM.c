
#include<stdio.h>
#include <string.h>

int bakiye=1000; 

void sifreilk () 
    char ilksifre[20];
    int i ;
    printf(" Yeni sifre olusturunuz (sadece rakam kullanınız)");
    scanf("%s",&ilksifre);
        for(i = 0; ilksifre[i] != '\0'; i++) 
            {
        if(ilksifre[i] < '0' || ilksifre[i] > '9') 
        {
            printf("Hatalı şifre! Şifre yalnızca rakamlardan oluşmalıdır.\n");
            return 0 ;

        }
    }
    printf ("Sifreniz:%s lütfen unutmayiniz. \n",ilksifre[20]);
}

int bilgiler(int islem) 
{
    int giris, cikis;

    switch (islem) 
    {
        case 1:

            printf("Bakiyeniz: %d\n", bakiye); 
            break;

        case 2:

            printf("Yatirmak istediginiz tutari giriniz: ");
            scanf("%d", &giris);
            bakiye += giris;
            printf("Yeni Bakiyeniz: %d\n", bakiye);
            break;

        case 3:
            printf("Cekmek istediginiz tutari giriniz: ");
            scanf("%d", &cikis);
              if (cikis > bakiye) 
              {
                printf("Yetersiz bakiye!\n");
              }
                else
                {
                    bakiye -= cikis;
                    printf("Yeni Bakiyeniz: %d\n", bakiye);
                }
        break;

        case 4:

            sifreilk();
            break;

        default:

            printf("Gecersiz islem.\n");
            break;

    }

    return bakiye;

}
    int main ()
{
      int sifre,islem,sonislem=1,yenisif;
      char girilenSifre[20]="1234";
      printf("*** Welcome ***\n");
      printf("Þifrenizi Giriniz Eger Kart iadesi istiyorsanız 1 tuşlayınız yoksa herhangi bir rakamı tuşlayınız");
       
      scanf("%s",&yenisif); 
        if(yenisif==1)
            {
            return 0;
            }

         else
        {
          printf("şifrenizi giriniz");
          scanf("%s",&girilenSifre);
            if (strcmp(girilenSifre, "1234") == 0)
            {

                do{
                   
                    printf("Hangi iþlemi yapmak istiyorsunuz");
                    printf("1:Bakiye Ögrenme\n");
                    printf("2:Para Yatirma\n");
                    printf("3:Para Çekme\n");
                    printf("4:Şifre Degiþtirme\n");
                    printf("Hangi islemi yapcaksaniz onu tuslayiniz");
                    scanf("%d",&islem);
                    bakiye = bilgiler(islem); 
                    printf("Son durumdaki bakiyeniz: %d\n", bakiye);
                    printf (" İşlem Yapmaya Devam Edicekmisiniz ");
                    printf("İşlem yapmaya devam etmek istiyor musunuz?\n");
                    printf("1: Evet\n");
                    printf("2: Hayır\n");
                    scanf("%d", &sonislem);

                if (sonislem != 1 && sonislem != 2) 
                {
                    printf("Hatalı giriş yaptınız!\n");
                    return 0;
                        }
                }
                    while (sonislem == 1);

                        if(sonislem==2) 
                            {
                        printf ("Bizi Kullandıgınız için teşekkür ederiz");
                            }
            }
                            else 
                            {
                                printf("Hatali şifre girmişssiniz");
                            }
        }

    return 0;

}
