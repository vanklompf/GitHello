#include "client.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

static void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void client_main(int port)
{
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int n;

    char buffer[256];

    int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (socketDescriptor < 0)
    {
        error("ERROR opening socket");
    }

    server = gethostbyname("localhost");
    if (server == NULL)
    {
        error("ERROR, no such host\n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(socketDescriptor,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        error("ERROR connecting");
    }

    n = write(socketDescriptor,"12345XXX",8);
    if (n < 0)
    {
         error("ERROR writing to socket");
    }
    memset(buffer,0,256);
    n = read(socketDescriptor,buffer,255);
    if (n < 0)
    {
         error("ERROR reading from socket");
    }
    printf("CLIENT: %s\n",buffer);
    close(socketDescriptor);
}
/*
�ona unika moich przyjaci� i rodziny.

Witam,

Postanowi�em napisa� na forum dla kobiet, poniewa� problem dotyczy kobiety, (mojej �ony) i mo�e wasz punkt widzenia co� wniesie do sprawy.
Wygl�da na dosy� b�ahy, ale mimo wszystko jest dla mnie przykry.

Problem w skr�cie wygl�da tak: moja �ona nie lubi, unika, a czasem r�wnie� stara si� izolowa� mnie od moich znajomych i mojej rodziny.
Sprawa jest troch� zwi�zana z jej charakterem, zdawa�em sobie z tego spraw�, ale z roku na rok problem si� nasila i zaczynam czu� z tym coraz gorzej.

Zacz�o si� od tego, �e lata temu na jednym ze spotka� z grup� moich znajomych (3 pary + jeden singiel) moj� �on� spotka�� jaka� niemi�a sytuacja, kto� si� zachowa� niedyplomatycznie (nie z grona moich najbli�szych znajomych), ja nie zareagowa�em odpowiednio zdecydowanie. Og�lnie nic wielkiego, co wtedy uzna�bym za jakie� dramatyczne wydarzenie, poprostu niezbyt mi�e pytanie na temat czego� w jej wygl�dzie. Po chyba roku powracaj�cych k��tni na temat moich znajomych i unikania przez ni� spotka� z nimi, w ramach kompromisu przysta�em, na to, �e b�d� si� z nimi spotyka� tylko sam (czyli raczej odpadaj� sylwestry, wesela itp.), ale ona nie b�dzie przeciwko temu walczy�a.
Co ciekawe, nie chcia�a si� spotyka� r�wnie� z par�, kt�rej podczas tego pechowego spotkania nie by�o. Tu powody sprowadzi�y si� do: bo ich nie lubi�.
By�o to dla mnie wyrzeczenie, bo by�em z�yty z tymi lu�dzmi i lubi�em sp�dza� z nimi czas. Moja poprzednia dziewczyna bardzo ich lubi�a, a oni lubieli j� i nawet nie zdawa�em sobie sprawy, �e kiedy� b�d� musia� dokonywa� wyboru �ona albo znajomi. Ale zale�a�o mi na �onie, a mia�em te� cich� nadziej�, �e czas leczy rany.. Z pozytyw�w, to pozwoli�a zaprosi� na nasze wesele moich znajomych. Posz�a te� na jedno wesele, na kt�rym byli i widzia�a si� z nimi mo�e 3 razy. Ale oczywi�cie m�wimy to o okresie dobrych kilku lat.


Po jakim� czasie �ona przeprowadzi�� si� do mnie. Mia�em tam znajomego ze studi�w (nie mia� nic wsp�lnego z tamt� grup�, wi�c by� "czysty"), na przestrzeni mo�e dw�ch-trzech lat spotykali�my si� z nim i jego �on�. Nie by�y to jakie� cz�ste spotkania, ale zawsze co�. Po jakim� czasie r�wnie� to zacz�o si� psu�. Po ka�dym spotkaniu moja �ona krytykowa�a ich, coraz bardziej unika�a tych spotka�, spotykali�my si� coraz rzadziej. Przez jaki� czas spotyka�em si� z kumplem sam przy piwie i unika�em temat�w odwiedzania si� w domach. Gdy po jakim� czasie unikania, w ko�cu chcia�em przyj�� ich zaproszenie, �ona zapowiedzia�a, �e wi�cej si� z nimi nie zobaczy, bo ... rok temu za p�no nas zaprosili po tym jak urodzi�o si� im dziecko.
Spotkanie ze znajomym z pracy i jego �on� gdzie� na mie�cie? Te� odpada, bo �ona jest wredna itp. itd.
Wyjazd na zaproszenie mojego znajomego i jego dziewczyny do Warszawy? Niee, bo b�dzie niezr�cznie/za s�abo go zna/itp.
W tym momencie znam jedn�, jedyn� osob� z kt�r� m�g�bym si� spotka� z moj� �on�. Oczywi�cie nie, �e ch�tnie, ale teoretycznie istnieje taka mo�liwo��.


Przez jaki� czas �ona mia�a swoich znajomych, jednych lubia�em bardziej, innych mniej. Ch�tnie si� z nimi spotyka�em, bo zawsze to jakie� wyj�cie do ludzi. Nawet zach�ca�em j� do tych spotka�, przygotowywa�em �arcie dla odwiedzaj�cych nas jej kole�anek itp. Niestety po jakim� czasie wszystko si� posypa�o, z najbli�sz� kole�ank� pok��ci�� si� tak, �e nie odzywaj� si� do siebie od prawie roku i chyba nigdy ju� nie b�d�, z drug� powoli traci kontakt, a trzeciej ch�opaka nie lubi, wi�c wiadomo.

Od pocz�tku zesz�ego roku spotkali�my si� wsp�lnie z lud�mi nie b�d�cymi cz�onkami naszych rodzin.. mo�e 4 razy? Sylwestry przez ostatnie lata sp�dzamy zwykle sami (znajomi zapraszaj� nas regularnie, ale musz� odm�wi�).
Dodam �e nie mamy dzieci, wi�c brak czasu nie jest tu problemem.
Ostatnio bywa gorzej, bo nawet kiedy pr�buj� wyj�� spotka� si� ze znajomymi sam, to �ona to torpeduje. Nie zawsze aktywnie, czasem subtelnie, ale czuj� coraz wi�kszy op�r. Pytana, powiedzia�a, �e jest zazdrosna, �e ciesz� si� na spotkania z lud�mi innymi ni� ona, bardziej ni� z ni�. Sama nie spotyka si� praktycznie nigdy, bo nie bardzo ma z kim, wi�c ka�de moje wyj�cie to jest "zostawienie jej samej".

Na cz�onk�w mojej rodziny te� ma "haki". Je�li chodzi o spotkania z nimi to walka jest o ka�dy kwadrans, pojawia si� tylko je�li naprawd� czuje �e jej wypada. Ale fakt, faktem - spotyka si�, wi�c czasem s� o to mi�dzy nami spi�cia, ale jest ok.
Jest r�wnie� zazdrosna o moje siostry. Jedna z nich mieszka w tym samym mie�cie co my, widuj� si� z ni� przelotnie mo�e raz w miesi�cu, ze dwie kr�kie rozmowy przez telefon. Stwierdzi�a, �e tworzymy z ni� "tr�jk�t"...
Przyk�adowo: po sp�dzeniu ca�ego weekendu z odwiedzaj�cymi nas jej rodzicami, oprowadzania ich, zabierania do restauracji, siedzenia z nimi 100% czasu �a�owa�a mi godziny na to, �ebym pogada� z siostrami o prezencie dla taty bo "Znowu z nimi tyle gadasz".


  */
