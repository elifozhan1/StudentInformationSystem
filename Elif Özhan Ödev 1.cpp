/******************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** PROGRAMLAMAYA GİRİŞ DERSİ
**
** ÖDEV NUMARASI: 1
** ÖĞRENCİ ADI: ELİF ÖZHAN
** ÖĞRENCİ NUMARASI: B221210001
** DERS GRUBU: B
******************************/

//Kütüphaneler

#include <iostream>
#include <locale.h>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;

/* Harf notunu bulan fonksiyonun ve not kontrol fonksiyonunun prototiplerini tanımladım. */

string HarfNotu(float Not);
float Kontrol(string giris, float minNot, float maxNot);

/* Menü seçeneğinde kullanılacak olan 8 fonksiyonun prototiplerini tanımladım. */

/*1*/ void SinifListesi();
/*2*/ float EnYuksekNot();
/*3*/ float EnDusukNot();
/*4*/ float Ortalama();
/*5*/ float StandartSapma();
/*6*/ float AralikSiralama(float n, float t);
/*7*/ float BasariAltOgrenciler(float n);
/*8*/ float BasariUstOgrenciler(float n);

// Tarih struct veri tipini tanımladım. Yapı üyeleri: gün, ay yıl.

struct Tarih
{
	int gun;
	int ay;
	int yil;

};

/* Ogrenci isimli bir struct veri tipi oluşturdum.Yapı üye değişkenleri: Adi, soyadi, No, kısa sınav1,
kısa sınav2, ödev1, ödev2, proje, vize, final ve Tarih struct veri türünden doğum tarihi. */

struct Ogrenci
{
	string ad;
	string soyad;
	string no;
	float kisasinav1;
	float kisasinav2;
	float odev1;
	float odev2;
	float proje;
	float vize;
	float final;
	float yilicinot;
	float basarinotu;
	Tarih dogumtarihi;

};

/* Belirlediğim 30 isim ve soy isim için iki string dizi oluşturdum. */

string ogrAdDizisi[30] = { "Gizem","Beste","Naz","Neşe","Eylül",
						"İlayda","Özge","Helin","Alev","Barış",
						"Can","Metin","Denizhan","Berkcan","Volkan",
						"Serkan","Tülay","Yasemin","Ayla","Leyla",
						"Hale","Hilal","Elif","Lale","Hakan",
						"Mete","Emre","Kaan","Melih","Aydın" };

string ogrSoyadDizisi[30] = { "Özhan","Çalışkan","Ayyıldız","Yılmaz","Kaya",
						 "Demir","Çelik","Şahin","Yıldız","Yıldırım",
						 "Öztürk","Aydın","Özdemir","Özkan","Ünlü",
						 "Karagöz","Çakır","Işık","Mavi","Tutumlu",
						 "Kitapçı","Gezgin","Gökçe","Ersoy","Kahveci",
						 "Ağaç","Bilgin","Yağmur","Akpınar","Karataş" };

/* 100 öğrenciyi atayabileceğim, Ogrenci veri tipinden bir dizi oluşturdum. */

Ogrenci OgrenciDizisi[100];
int ogrencisayisi;

int main()
{
	/* Türkçe karakter desteği için */
	setlocale(LC_ALL, "Turkish");

	// Program içinde kullanılan değişkenler tanımladım.
	int programdongu;
	float not1 = 0.0;
	float not2 = 0.0;
	float not3 = 0.0;
	float not4 = 0.0;

	/* Güzel görünmesi ve rahat anlaşılabilmesi için konsol ekranına yapılabilecek işlemleri yazdırdım. */
	cout << "HOŞGELDİNİZ" << endl << endl;
	do {

		cout << "Yapılacak işlem için öğenci bilgilerini nasıl belirlemek istediğinizi seçiniz: " << endl << endl;
		cout << "Seçenek 1: Rastgele" << endl << "Seçenek 2: Giriş yaparak" << endl << endl;
		int secenek;
		cin >> secenek;

		if (secenek == 1) // Seçenek 1 için kodlar
		{
			/* Bu seçenekte bütün öğrencilerin isimlerinin, soyisimlerinin ve bütün ders notlarının random belirlenmesini sağlamak adına bir for döngüsü oluşturdum. */
			srand(time(NULL));
			ogrencisayisi = 100;

			for (int i = 0; i < ogrencisayisi; i++) // 100 öğrenci için çalışacağından "i = 0; i < 100" yazdım.
			{
				OgrenciDizisi[i].ad = ogrAdDizisi[rand() % 30];
				OgrenciDizisi[i].soyad = ogrSoyadDizisi[rand() % 30];

				if (i >= 0 && i <= 10)
				{
					OgrenciDizisi[i].kisasinav1 = rand() % 41;
					OgrenciDizisi[i].kisasinav2 = rand() % 41;
					OgrenciDizisi[i].odev1 = rand() % 41;
					OgrenciDizisi[i].odev2 = rand() % 41;
					OgrenciDizisi[i].proje = rand() % 41;
					OgrenciDizisi[i].vize = rand() % 41;
					OgrenciDizisi[i].final = rand() % 41;
				}

				else if (i > 10 && i <= 60)
				{
					OgrenciDizisi[i].kisasinav1 = 40 + (rand() % 31);
					OgrenciDizisi[i].kisasinav2 = 40 + (rand() % 31);
					OgrenciDizisi[i].odev1 = 40 + (rand() % 31);
					OgrenciDizisi[i].odev2 = 40 + (rand() % 31);
					OgrenciDizisi[i].proje = 40 + (rand() % 31);
					OgrenciDizisi[i].vize = 40 + (rand() % 31);
					OgrenciDizisi[i].final = 40 + (rand() % 31);
				}

				else if (i > 60 && i < 75)
				{
					OgrenciDizisi[i].kisasinav1 = 70 + (rand() % 11);
					OgrenciDizisi[i].kisasinav2 = 70 + (rand() % 11);
					OgrenciDizisi[i].odev1 = 70 + (rand() % 11);
					OgrenciDizisi[i].odev2 = 70 + (rand() % 11);
					OgrenciDizisi[i].proje = 70 + (rand() % 11);
					OgrenciDizisi[i].vize = 70 + (rand() % 11);
					OgrenciDizisi[i].final = 70 + (rand() % 11);
				}

				else if (i > 75 && i < 100)
				{
					OgrenciDizisi[i].kisasinav1 = 80 + (rand() % 21);
					OgrenciDizisi[i].kisasinav2 = 80 + (rand() % 21);
					OgrenciDizisi[i].odev1 = 80 + (rand() % 21);
					OgrenciDizisi[i].odev2 = 80 + (rand() % 21);
					OgrenciDizisi[i].proje = 80 + (rand() % 21);
					OgrenciDizisi[i].vize = 80 + (rand() % 21);
					OgrenciDizisi[i].final = 80 + (rand() % 21);
				}

				/* Bu bölümde öğrencilerin yukarıda belirlenen random notlara göre yıl içi başarı notunu ve genel başarı notunu hesapladım. */

				OgrenciDizisi[i].yilicinot = (OgrenciDizisi[i].vize) * (50.0 / 100.0) + (OgrenciDizisi[i].kisasinav1) * (7.0 / 100.0) +
					(OgrenciDizisi[i].kisasinav2) * (7.0 / 100.0) + (OgrenciDizisi[i].odev1) * (10.0 / 100.0) + (OgrenciDizisi[i].odev2) * (10.0 / 100.0) +
					(OgrenciDizisi[i].proje) * (16.0 / 100.0);

				OgrenciDizisi[i].basarinotu = (OgrenciDizisi[i].yilicinot) * (55.0 / 100.0) + (OgrenciDizisi[i].final) * (45.0 / 100.0);


			}

			int birinciistek;

			do {
				/* Birinci seçenek için bir menü oluşturdum. */

				cout << "YAPMAK İSTEDİĞİNİZ İŞLEMİ SEÇİNİZ: " << endl << endl;
				cout << "1) Sınıf listesi yazdır." << endl;
				cout << "2) Sınıfın en yüksek notunu hesapla." << endl;
				cout << "3) Sınıfın en düşük notunu hesapla." << endl;
				cout << "4) Sınıf ortalamasını hesapla." << endl;
				cout << "5) Sınıfın standart sapmasını hesapla." << endl;
				cout << "6) Başarı notu belirli bir aralıkta olanları listele." << endl;
				cout << "7) Başarı notu belirtilen bir değerin altında olan öğrencilerin listesi al." << endl;
				cout << "8) Başarı notu belirtilen bir değerin üstünde olan öğrencilerin listesi al." << endl;
				int yapilacakislem = 0;
				cin >> yapilacakislem;

				if (yapilacakislem == 1) SinifListesi();
				else if (yapilacakislem == 2) cout << EnYuksekNot();
				else if (yapilacakislem == 3) cout << EnDusukNot();
				else if (yapilacakislem == 4) cout << Ortalama();
				else if (yapilacakislem == 5) cout << StandartSapma();
				else if (yapilacakislem == 6)
				{
					cout << "Not aralığı için iki değer giriniz: " << endl;
					cin >> not1;
					cin >> not2;
					cout << AralikSiralama(not1, not2);

				}
				else if (yapilacakislem == 7)
				{
					cout << "Belirli bir notun altındaki öğrencileri görüntülemek için bir değer giriniz: " << endl;
					cin >> not3;
					cout << BasariAltOgrenciler(not3);

				}
				else if (yapilacakislem == 8)
				{
					cout << "Belirli bir notun üstündeki öğrencileri görüntülemek için bir değer giriniz: " << endl;
					cin >> not4;
					cout << BasariUstOgrenciler(not4);

				}

				cout << endl << "Birinci seçenek için işlemlere devam etmek istiyorsanız 1'e istemiyorsanız 0'a basın." << endl;
				cin >> birinciistek;

			} while (birinciistek == 1);

		}

		else if (secenek == 2) // Seçenek 2 için kodlar
		{
			/* Öncelikle işlem yapılacak öğrenci sayısını kullanıcıdan aldım. */
			
			cout << "Bilgi girişi yapılacak öğrenci sayısı: " << endl;
			cin >> ogrencisayisi;
			cout << "Öğrenci bilgilerini giriniz." << endl;

			/* Kullanıcın girdiği değere kadar giden bir döngü kurdum. */

			for (int i = 1; i <= ogrencisayisi; i++)
			{
				cout << "Öğrenci Adı: ";
				cin >> OgrenciDizisi[i].ad;
				cout << "Öğrenci Soyadı: ";
				cin >> OgrenciDizisi[i].soyad;
				cout << "Öğrenci No: ";
				cin >> OgrenciDizisi[i].no;
				cout << "Öğrenci Doğum Tarihi (Gün / Ay / Yıl): ";
				cin >> OgrenciDizisi[i].dogumtarihi.gun;
				cin >> OgrenciDizisi[i].dogumtarihi.ay;
				cin >> OgrenciDizisi[i].dogumtarihi.yil;
				OgrenciDizisi[i].kisasinav1 = Kontrol("Öğrencinin Kısa Sınav 1 Notu: ", 0.0 ,100.0);
				OgrenciDizisi[i].kisasinav2 = Kontrol("Öğrencinin Kısa Sınav 2 Notu: ", 0.0, 100.0);
				OgrenciDizisi[i].odev1 = Kontrol("Öğrencinin Ödev 1 Notu: ", 0.0, 100.0);
				OgrenciDizisi[i].odev2 = Kontrol("Öğrencinin Ödev 2 Notu: ", 0.0, 100.0);
				OgrenciDizisi[i].proje = Kontrol("Öğrencinin Proje Notu: ", 0.0, 100.0);
				OgrenciDizisi[i].vize = Kontrol("Öğrencinin Vize Notu: ", 0.0, 100.0);
				OgrenciDizisi[i].final = Kontrol("Öğrencinin Final Notu: ", 0.0, 100.0);

				OgrenciDizisi[i].yilicinot = (OgrenciDizisi[i].vize) * (50.0 / 100.0) + (OgrenciDizisi[i].kisasinav1) * (7.0 / 100.0) +
					(OgrenciDizisi[i].kisasinav2) * (7.0 / 100.0) + (OgrenciDizisi[i].odev1) * (10.0 / 100.0) + (OgrenciDizisi[i].odev2) * (10.0 / 100.0) +
					(OgrenciDizisi[i].proje) * (16.0 / 100.0);

				OgrenciDizisi[i].basarinotu = (OgrenciDizisi[i].yilicinot) * (55.0 / 100.0) + (OgrenciDizisi[i].final) * (45.0 / 100.0);
			}

			int ikinciistek;

			do{

				/* İkinci seçenek için de bir menü oluşturdum. */

				cout << "YAPMAK İSTEDİĞİNİZ İŞLEMİ SEÇİNİZ: " << endl << endl;
				cout << "1) Sınıf listesi yazdır." << endl;
				cout << "2) Sınıfın en yüksek notunu hesapla." << endl;
				cout << "3) Sınıfın en düşük notunu hesapla." << endl;
				cout << "4) Sınıf ortalamasını hesapla." << endl;
				cout << "5) Sınıfın standart sapmasını hesapla." << endl;
				cout << "6) Başarı notu belirli bir aralıkta olanları listele." << endl;
				cout << "7) Başarı notu belirtilen bir değerin altında olan öğrencilerin listesi al." << endl;
				cout << "8) Başarı notu belirtilen bir değerin üstünde olan öğrencilerin listesi al." << endl;
				int yapilacakislem = 0;
				cin >> yapilacakislem;

				if (yapilacakislem == 1) SinifListesi();
				else if (yapilacakislem == 2) cout << EnYuksekNot();
				else if (yapilacakislem == 3) cout << EnDusukNot();
				else if (yapilacakislem == 4) cout << Ortalama();
				else if (yapilacakislem == 5) cout << StandartSapma();
				else if (yapilacakislem == 6)
				{
					cout << "Not aralığı için iki değer giriniz: " << endl;
					cin >> not1;
					cin >> not2;
					cout << AralikSiralama(not1, not2);

				}
				else if (yapilacakislem == 7)
				{
					cout << "Belirli bir notun altındaki öğrencileri görüntülemek için bir değer giriniz: " << endl;
					cin >> not3;
					cout << BasariAltOgrenciler(not3);

				}
				else if (yapilacakislem == 8)
				{
					cout << "Belirli bir notun üstündeki öğrencileri görüntülemek için bir değer giriniz: " << endl;
					cin >> not4;
					cout << BasariUstOgrenciler(not4);

				}

				cout << endl << "İkinci seçenek için işlemlere devam etmek istiyorsanız 1'e istemiyorsanız 0'a basın." << endl;
				cin >> ikinciistek;

			} while (ikinciistek == 1);


		}

		/* Programın çalışmaya devam edip etmeyeceği bilgisini kullanıcıdan istedim. Böylelikle, bir döngü kullanımıyla programda devamlılık isteğe
		bağlı olarak sağlanmış oldu. */

		cout << "Programın çalışmaya devam etmesini istiyor musunuz? (Evet: 1, Hayır: 0)" << endl;
		cin >> programdongu;

	} while (programdongu == 1);
}

/* Öğrencilerin 100’lük notunu harfe çeviren bir fonksiyon yazdım. */

string HarfNotu(float Not)
{
	string OgrHarfNotu;
	if (90 <= Not && Not <= 100) OgrHarfNotu = "AA";
	else if (85 <= Not && Not < 90) OgrHarfNotu = "BA";
	else if (80 <= Not && Not < 85) OgrHarfNotu = "BB";
	else if (70 <= Not && Not < 80) OgrHarfNotu = "CB";
	else if (60 <= Not && Not < 70) OgrHarfNotu = "CC";
	else if (55 <= Not && Not < 60) OgrHarfNotu = "DC";
	else if (50 <= Not && Not < 55) OgrHarfNotu = "DD";
	else if (40 <= Not && Not < 50) OgrHarfNotu = "FD";
	else if (0 <= Not && Not < 40) OgrHarfNotu = "FF";
	else OgrHarfNotu = "Geçersiz Harf Notu";
	return OgrHarfNotu;
}

/* Girilen notun doğruluğunu kontrol eden bir fonksiyon yazdım. */

float Kontrol(string giris, float minNot, float maxNot)
{
	float sinavNotu;
	do
	{
		cout << giris;
		cin >> sinavNotu;
	} while ((sinavNotu < minNot || sinavNotu > maxNot));

	return sinavNotu;
}

/* Sınıf listesi yazdırmak için bir fonksiyon yazdım. */

void SinifListesi()
{
	for (int i = 1; i <= ogrencisayisi; i++)
	{
		cout << setw(9) << OgrenciDizisi[i].ad << setw(9) << OgrenciDizisi[i].soyad << setw(20) << OgrenciDizisi[i].basarinotu << setw(9) <<
			HarfNotu(OgrenciDizisi[i].basarinotu) << endl;

		if (i % 20 == 0)
		{
			system("pause");
			system("cls");
		}
	}
}

/* En yüksek notu hesaplayan bir fonksiyon yazdım. */

float EnYuksekNot()
{
	float enyuksek = 0.0;

	for (int i = 0; i < ogrencisayisi; i++)
	{
		if (OgrenciDizisi[i].basarinotu > enyuksek)
			enyuksek = OgrenciDizisi[i].basarinotu;
	}

	return enyuksek;
}

/* En düşük notu hesaplayan bir fonksiyon yazdım. */

float EnDusukNot()
{
	float endusuk = 100000000.0;

	for (int i = 0; i < ogrencisayisi; i++)
	{
		if (OgrenciDizisi[i].basarinotu < endusuk)
			endusuk = OgrenciDizisi[i].basarinotu;
	}

	return endusuk;
}

/* Ortalamayı hesaplayan bir fonksiyon yazdım. */

float Ortalama()
{
	float ort = 0.0;
	float toplam = 0.0;

	for (int i = 0; i < ogrencisayisi; i++)
	{
		toplam += OgrenciDizisi[i].basarinotu;
	}

	ort = toplam / 100;
	return ort;
}

/* Standart sapmayı hesaplayan bir fonksiyon yazdım. */

float StandartSapma()
{
	float s_sapma = 0.0;
	float ort = Ortalama();

	for (int i = 0; i < ogrencisayisi; i++)
	{
		s_sapma += pow(OgrenciDizisi[i].basarinotu, 2);

	}

	s_sapma /= (100 - 1);
	s_sapma = sqrt(s_sapma);
	return s_sapma;

}

/* Başarı notu belirli bir aralıkta olanları listeleyen bir fonksiyon yazdım. */

float AralikSiralama(float n, float t)
{
	for (int i = 0; i < ogrencisayisi; i++)
	{
		if ((OgrenciDizisi[i].basarinotu < n && OgrenciDizisi[i].basarinotu > t) || (OgrenciDizisi[i].basarinotu > n && OgrenciDizisi[i].basarinotu < t))
			cout << OgrenciDizisi[i].ad << " " << OgrenciDizisi[i].soyad << " " << OgrenciDizisi[i].basarinotu << endl;
	}

	return n, t;
}

/* Başarı notu belirtilen bir değerin altında olan öğrencilerin listesini alabilen bir fonksiyon yazdım. */

float BasariAltOgrenciler(float n)
{
	for (int i = 0; i < ogrencisayisi; i++)
	{
		if (OgrenciDizisi[i].basarinotu < n) cout << OgrenciDizisi[i].ad << " " << OgrenciDizisi[i].soyad << " " << OgrenciDizisi[i].basarinotu << endl;
	}

	return n;
}

/* Başarı notu belirtilen bir değerin üstünde olan öğrencilerin listesini alabilen bir fonksiyon yazdım. */

float BasariUstOgrenciler(float n)
{
	for (int i = 0; i < ogrencisayisi; i++)
	{
		if (OgrenciDizisi[i].basarinotu > n) cout << OgrenciDizisi[i].ad << " " << OgrenciDizisi[i].soyad << " " << OgrenciDizisi[i].basarinotu << endl;
	}

	return n;
}