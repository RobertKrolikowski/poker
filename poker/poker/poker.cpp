#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

char talia[52];
char taliaznak[52];
char znak[4]={3,4,5,6};
int numerkarty = 51, stawka = 0,kasa = 1000,numerwyboru=0,pozyczka=0;
char wybor[6]={94},zmiana = 0,zaznaczenie[5]={0};
char reka[5],rekaznak[5];

//funkcja do tasowania kart
void tasowanie()
{
	int i=0,t,tt;
	char pojemnik;
	for(;i < 200;i++)
	{
		t=rand() % 52;
		tt=rand() % 52;
		pojemnik = talia[t];
		talia[t] = talia[tt];
		talia[tt] = pojemnik;
		pojemnik = taliaznak[t];
		taliaznak[t] = taliaznak[tt];
		taliaznak[tt] = pojemnik;
	}
}
//wyczyszczenie wyboru
void czyszczenie()
{
	numerwyboru = 0;
	wybor[0] = 94;
	for(int a=1; a < 6;a++) wybor[a]=0;

}
//funkcja do przesuwania strzalek
void menu()
{
		//kasowanie strzalki "^"
		if(zmiana != 13)
		{
			for(int a=0;a < 6; a++)
			{
				if(wybor[a] != 35) wybor[a] = 0 ;
			}
		}
		//przesuniecie wyboru
		if(zmiana == 100)
		{
			if(numerwyboru == 5) numerwyboru = 0;
			else numerwyboru+=1;
			wybor[numerwyboru]=94;
		}
		else if(zmiana == 97)
		{
			if(numerwyboru == 0) numerwyboru = 5; 
			else numerwyboru-=1;
			wybor[numerwyboru]=94;
		
		}
		//jesli nacisniemy inny klawisz niz "a" lub "d" nic sie nie stanie
		else wybor[numerwyboru]=94;
}
void tabelka()
{
	printf("Poruszasz sie klawiszami: \"a\" w lewo natomiast \"d\" w prawo.\n");
	printf("Klawiszem enter zatwierdzasz\n");
	printf("Poker Krolewski - %7d$\n",stawka * 1000);
	printf("Poker           - %7d$\n",stawka * 500);	
	printf("Kareta          - %7d$\n",stawka * 300);
	printf("Full            - %7d$\n",stawka * 100);
	printf("Kolor           - %7d$\n",stawka * 50);
	printf("Strit           - %7d$\n",stawka * 10);
	printf("Trojka          - %7d$\n",stawka * 5);
	printf("Dwie Pary       - %7d$\n",stawka * 2);
	printf("Para            - %7d$\n",stawka * 1);
	printf("Aktualnie masz %d$\n",kasa);
	printf("Twoja stawka to %d$\n",stawka);
}


int main()
{
	srand(time(0));
	//przypisanie kart do tablicy
	for(int a = 0,z = 0,b = 0; a < 4;a++,z++,b+=13)
	{
		for(int t = 0; t < 13;t++)
		{
			talia[t+b] = 48+t;
			taliaznak[t+b] = znak[z];
			if(t == 10)
			{
			talia[t+b] = 'J';
			taliaznak[t+b] = znak[z];
			}
			if(t == 11)
			{
			talia[t+b] = 'D';
			taliaznak[t+b] = znak[z];
			}
			if(t == 12)
			{
			talia[t+b] = 'K';
			taliaznak[t+b] = znak[z];
			}
			if(t == 1)
			{
			talia[t+b] = 'A';
			taliaznak[t+b] = znak[z];
			}
		}
	}
	
	//wybor stawki
	do
	{
		czyszczenie();
		tasowanie();
		do
		{
			system("cls");
			printf("Witam w grze poker\n");
			printf("Poruszasz sie klawiszami: \"a\" w lewo natomiast \"d\" w prawo.\n");
			printf("Wybierz stawke\n");
			printf("Masz aktualnie %d$\n",kasa);
			printf("1\t10\t50\t100\t500\t1000\n");
			printf("%c\t%c\t%c\t%c\t%c\t%c\t\n",wybor[0],wybor[1],wybor[2],wybor[3],wybor[4],wybor[5]);
			zmiana = getch();
			menu();
			if((wybor[0] == 94) && (kasa >= 1) ) stawka = 1;
			else if((wybor[1] == 94) && (kasa >= 10))	stawka = 10;
			else if((wybor[2] == 94) && (kasa >= 50))	stawka = 50;
			else if((wybor[3] == 94) && (kasa >= 100))	stawka = 100;
			else if((wybor[4] == 94) && (kasa >= 500))	stawka = 500;
			else if((wybor[5] == 94) && (kasa >= 1000)) stawka = 1000;
			else zmiana = 94;
		}
		while(zmiana != 13);
		//odjecie postawionej stawki od posiadanej kasy i wyczyszczenie zaznaczen i woborow
		kasa -= stawka;
		for (int a = 0; a < 5;a++ )
		{
			zaznaczenie[a]=0;
		}
		czyszczenie();
		//pokazanie kart i ich wybor
		do
		{
			system("cls");
			tabelka();
			printf("Wybierz karty ktore chcesz zatrzymac\n");
			printf("Twoje Karty to:\n\n");	
			printf("%c\t%c\t%c\t%c\t%c\t\n",zaznaczenie[0],zaznaczenie[1],zaznaczenie[2],zaznaczenie[3],zaznaczenie[4]);
			for(int a = 0;a < 5;a++)
			{
				if(talia[numerkarty-a] == '0' ) printf("1");
				printf("%c%c\t",talia[numerkarty-a],taliaznak[numerkarty-a]);
			}
			printf("Wymiana kart\n");
			printf("%c\t%c\t%c\t%c\t%c\t%c",wybor[0],wybor[1],wybor[2],wybor[3],wybor[4],wybor[5]);

			zmiana = getch();
			menu();
			//zaznaczenie i odznaczenie karty 
			for(int a = 0; a < 5;a++)
			{
				if((zmiana == 13) && (wybor[a] == 94) && (zaznaczenie[a] == 0))
				{
					zaznaczenie[a] = 35;
				}
				else if( (zmiana ==  13) && (zaznaczenie[a] == 35) && (wybor[a] == 94) )
				{
					zaznaczenie[a] = 0;
				}
			}
			if((zmiana == 13) && (wybor[5] == 94))  break;		
		}
		while(wybor[5] !=1 );

		//sprawdzanie jakie karty zostaly zaznaczone i wymiana nie wybranych kart na nowe oraz
		//przypisanie kart do reki
		system("cls");
		tabelka();
		printf("\nTwoje karty to:\n");
		for(int a = 0; a < 5 ;a++)
		{
			if(zaznaczenie[a] == 35)
			{
				if(talia[51-a] == '0') printf("1");
				reka[a] = talia[51-a];
				rekaznak[a] = taliaznak[51-a];
			}
			else
			{
				if(talia[46-a] == '0') printf("1");
				reka[a] = talia[46-a];
				rekaznak[a] = taliaznak[46-a];
			}
			printf("%c%c\t",reka[a],rekaznak[a]);
		}
		printf("\n");
		//sprawdzanie czy gracz cos wygral
		//zmienne potrzebne do sprawdzenie czy sie ma kolor ,pokera itd.
		int kolor = 0,reka1[5],licznik,para=0,trojka=0,kareta=0,kolejnosc=0;
		for(int a = 0; a < 5;a++)
		{
			if(rekaznak[a] == rekaznak[a+1]) kolor++;
		}


		//przypisanie karta numeru
		for(int a=0;a < 5;a++)
		{
			if((reka[a] >= 50) && (reka[a] <= 57)) reka1[a]= reka[a]- 48;
			if(reka[a] == 48) reka1[a] = 10;
			if(reka[a] == 74) reka1[a] = 11;
			if(reka[a] == 68) reka1[a] = 12;
			if(reka[a] == 75) reka1[a] = 13;
			if(reka[a] == 65) reka1[a] = 14;
		}
		//sortowanie numerow kart
		do
		{
			licznik = 0;
			for(int a=0,b;a < 4;a++)
			{
				if(reka1[a] > reka1[a+1])
				{
					b = reka1[a];
					reka1[a]=reka1[a+1];
					reka1[a+1]=b;
					licznik++;
				}
			}
		}
		while(licznik);
		//sprawdzenie czy karty sa pokolei
		for(int a=0;a < 4;a++)
		{
			if (reka1[a] == reka1[a+1]-1) kolejnosc++;
		}
		//sprawdzanie czy sie ma pary , trujke lub karete
		for(int a = 0,b = 1; a < 4 ;a++,b = 1)
		{
			if(reka1[a] == reka1[a+b])
			{
				b++;
				para++;
				if(reka1[a] == reka1[a+b])
				{
					b++;
					trojka++;
					para--;
					if(reka1[a] == reka1[a+b])
					{
						a++;
						kareta++;
						para--;
						trojka--;
					}
					a++;
				}
				a++;
			}
		}
		//sprawdzanie co sie wygrlo
		if (kolor==4)
		{
			if (kolejnosc == 4)
			{
				if(reka1[0] == 10)
				{
					printf("Masz pokera krolewskiego. Wygrales %d$\n",stawka*1000);
					kasa+=stawka * 1000;
				}
				else 
				{
					printf("Masz pokera. Wygrales %d$\n",stawka*500);
					kasa+=stawka * 500;
				}
			}
			else 
			{	
				printf("Masz kolor\n");
				kasa += stawka * 50;
			}
		}
		else if(kareta == 1)
		{
			printf("Masz karete. Wygrales %d$\n",stawka*300);
			kasa += stawka * 300;
		}
		else if(trojka == 1)
		{
			if(para == 1)
			{
				printf("Masz Fulla. Wygrales %d$\n",stawka*100);
				kasa += stawka * 100;
				para=0;
			}
			else if(kolor==4)
			{
				printf("Masz kolor\n");
				kasa += stawka * 50;
			}
			else if (kolejnosc == 4)
			{
					printf("Masz strita. Wygrales %d$\n",stawka*10);
					kasa+=stawka * 10;
			}
			else
			{
				printf("Masz trojke, Wygrales %d$\n",stawka*5);
				kasa += stawka * 5;
			}
		}
		else if(para == 1)
		{
			printf("Masz jedna pare. Wygrales %d$\n",stawka*1);
			kasa +=	stawka * 1;

		}
		else if(para == 2)
		{
			printf("Masz dwie pary. Wygrales %d$\n",stawka*2);
			kasa+= stawka * 2;
		}
		else printf("Przegrales\n");

		//ostatnie menu z zapytaniem czy chcesz zagrac jeszcze raz
		getch();
		czyszczenie();
		do
		{
			system("cls");
			printf("Aktualnie masz %d$\n",kasa);
			printf("Czy chcesz zagrac jeszcze raz??\nTAK\tNIE\n");
			printf("%c\t%c",wybor[0],wybor[1]);
			zmiana= getch();
			//kasowanie strzalki "^"
			if(zmiana != 13)
			{
				for(int a=0;a < 2; a++)
				{
					if(wybor[a] != 35) wybor[a] = 0 ;
				}
			}
			//przesuniecie wyboru
			if(zmiana == 100)
			{
				if(numerwyboru == 1) numerwyboru = 0;
				else numerwyboru+=1;
				wybor[numerwyboru]=94;
			}
			else if(zmiana == 97)
			{
				if(numerwyboru == 0) numerwyboru = 1; 
				else numerwyboru-=1;
				wybor[numerwyboru]=94;
		
			}
			//jesli nacisniemy inny klawisz niz "a" lub "d" nic sie nie stanie
			else 
			{
				wybor[numerwyboru]=94;
			}
			if ((kasa == 0) && (wybor[0] == 94) && (zmiana == 13))
			{
				printf("\nWszystko juz przegrales ale dam ci pozyczke w wysokoscli 1000$");
				pozyczka += 1000;
				kasa = 1000;
				getch();
			}
		}
		while(zmiana != 13);
	}
	while(wybor[0] == 94);
	getchar();
	return 0;
}
