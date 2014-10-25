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
¯ona unika moich przyjació³ i rodziny.

Witam,

Postanowi³em napisaæ na forum dla kobiet, poniewa¿ problem dotyczy kobiety, (mojej ¿ony) i mo¿e wasz punkt widzenia coœ wniesie do sprawy.
Wygl¹da na dosyæ b³ahy, ale mimo wszystko jest dla mnie przykry.

Problem w skrócie wygl¹da tak: moja ¿ona nie lubi, unika, a czasem równie¿ stara siê izolowaæ mnie od moich znajomych i mojej rodziny.
Sprawa jest trochê zwi¹zana z jej charakterem, zdawa³em sobie z tego sprawê, ale z roku na rok problem siê nasila i zaczynam czuæ z tym coraz gorzej.

Zaczê³o siê od tego, ¿e lata temu na jednym ze spotkañ z grup¹ moich znajomych (3 pary + jeden singiel) moj¹ ¿onê spotka³¹ jakaœ niemi³a sytuacja, ktoœ siê zachowa³ niedyplomatycznie (nie z grona moich najbli¿szych znajomych), ja nie zareagowa³em odpowiednio zdecydowanie. Ogólnie nic wielkiego, co wtedy uzna³bym za jakieœ dramatyczne wydarzenie, poprostu niezbyt mi³e pytanie na temat czegoœ w jej wygl¹dzie. Po chyba roku powracaj¹cych k³ótni na temat moich znajomych i unikania przez ni¹ spotkañ z nimi, w ramach kompromisu przysta³em, na to, ¿e bêdê siê z nimi spotyka³ tylko sam (czyli raczej odpadaj¹ sylwestry, wesela itp.), ale ona nie bêdzie przeciwko temu walczy³a.
Co ciekawe, nie chcia³a siê spotykaæ równie¿ z par¹, której podczas tego pechowego spotkania nie by³o. Tu powody sprowadzi³y siê do: bo ich nie lubiê.
By³o to dla mnie wyrzeczenie, bo by³em z¿yty z tymi luŸdzmi i lubi³em spêdzaæ z nimi czas. Moja poprzednia dziewczyna bardzo ich lubi³a, a oni lubieli j¹ i nawet nie zdawa³em sobie sprawy, ¿e kiedyœ bêdê musia³ dokonywaæ wyboru ¿ona albo znajomi. Ale zale¿a³o mi na ¿onie, a mia³em te¿ cich¹ nadziejê, ¿e czas leczy rany.. Z pozytywów, to pozwoli³a zaprosiæ na nasze wesele moich znajomych. Posz³a te¿ na jedno wesele, na którym byli i widzia³a siê z nimi mo¿e 3 razy. Ale oczywiœcie mówimy to o okresie dobrych kilku lat.


Po jakimœ czasie ¿ona przeprowadzi³¹ siê do mnie. Mia³em tam znajomego ze studiów (nie mia³ nic wspólnego z tamt¹ grup¹, wiêc by³ "czysty"), na przestrzeni mo¿e dwóch-trzech lat spotykaliœmy siê z nim i jego ¿on¹. Nie by³y to jakieœ czêste spotkania, ale zawsze coœ. Po jakimœ czasie równie¿ to zaczê³o siê psuæ. Po ka¿dym spotkaniu moja ¿ona krytykowa³a ich, coraz bardziej unika³a tych spotkañ, spotykaliœmy siê coraz rzadziej. Przez jakiœ czas spotyka³em siê z kumplem sam przy piwie i unika³em tematów odwiedzania siê w domach. Gdy po jakimœ czasie unikania, w koñcu chcia³em przyj¹æ ich zaproszenie, ¿ona zapowiedzia³a, ¿e wiêcej siê z nimi nie zobaczy, bo ... rok temu za póŸno nas zaprosili po tym jak urodzi³o siê im dziecko.
Spotkanie ze znajomym z pracy i jego ¿on¹ gdzieœ na mieœcie? Te¿ odpada, bo ¿ona jest wredna itp. itd.
Wyjazd na zaproszenie mojego znajomego i jego dziewczyny do Warszawy? Niee, bo bêdzie niezrêcznie/za s³abo go zna/itp.
W tym momencie znam jedn¹, jedyn¹ osobê z któr¹ móg³bym siê spotkaæ z moj¹ ¿on¹. Oczywiœcie nie, ¿e chêtnie, ale teoretycznie istnieje taka mo¿liwoœæ.


Przez jakiœ czas ¿ona mia³a swoich znajomych, jednych lubia³em bardziej, innych mniej. Chêtnie siê z nimi spotyka³em, bo zawsze to jakieœ wyjœcie do ludzi. Nawet zachêca³em j¹ do tych spotkañ, przygotowywa³em ¿arcie dla odwiedzaj¹cych nas jej kole¿anek itp. Niestety po jakimœ czasie wszystko siê posypa³o, z najbli¿sz¹ kole¿ank¹ pok³óci³¹ siê tak, ¿e nie odzywaj¹ siê do siebie od prawie roku i chyba nigdy ju¿ nie bêd¹, z drug¹ powoli traci kontakt, a trzeciej ch³opaka nie lubi, wiêc wiadomo.

Od pocz¹tku zesz³ego roku spotkaliœmy siê wspólnie z ludŸmi nie bêd¹cymi cz³onkami naszych rodzin.. mo¿e 4 razy? Sylwestry przez ostatnie lata spêdzamy zwykle sami (znajomi zapraszaj¹ nas regularnie, ale muszê odmówiæ).
Dodam ¿e nie mamy dzieci, wiêc brak czasu nie jest tu problemem.
Ostatnio bywa gorzej, bo nawet kiedy próbujê wyjœæ spotkaæ siê ze znajomymi sam, to ¿ona to torpeduje. Nie zawsze aktywnie, czasem subtelnie, ale czujê coraz wiêkszy opór. Pytana, powiedzia³a, ¿e jest zazdrosna, ¿e cieszê siê na spotkania z ludŸmi innymi ni¿ ona, bardziej ni¿ z ni¹. Sama nie spotyka siê praktycznie nigdy, bo nie bardzo ma z kim, wiêc ka¿de moje wyjœcie to jest "zostawienie jej samej".

Na cz³onków mojej rodziny te¿ ma "haki". Jeœli chodzi o spotkania z nimi to walka jest o ka¿dy kwadrans, pojawia siê tylko jeœli naprawdê czuje ¿e jej wypada. Ale fakt, faktem - spotyka siê, wiêc czasem s¹ o to miêdzy nami spiêcia, ale jest ok.
Jest równie¿ zazdrosna o moje siostry. Jedna z nich mieszka w tym samym mieœcie co my, widujê siê z ni¹ przelotnie mo¿e raz w miesi¹cu, ze dwie krókie rozmowy przez telefon. Stwierdzi³a, ¿e tworzymy z ni¹ "trójk¹t"...
Przyk³adowo: po spêdzeniu ca³ego weekendu z odwiedzaj¹cymi nas jej rodzicami, oprowadzania ich, zabierania do restauracji, siedzenia z nimi 100% czasu ¿a³owa³a mi godziny na to, ¿ebym pogada³ z siostrami o prezencie dla taty bo "Znowu z nimi tyle gadasz".


  */
