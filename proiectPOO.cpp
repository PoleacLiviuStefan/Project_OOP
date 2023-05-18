#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;


class Reclama
{

private:

    string platformaReclama;
    double CPC;
    int impact, interactiuni;

public:
    Reclama() : platformaReclama(""), CPC(0.0), impact(0), interactiuni(0) {}
    Reclama(string platformaReclamaI, double CPCI, int impactI, int interactiuniI)
    {
        platformaReclama = platformaReclamaI;
        CPC = CPCI;
        impact = impactI;
        interactiuni = interactiuniI;
    }

    Reclama(const Reclama& r)  //copy constructor
    {
        platformaReclama = r.platformaReclama;
        CPC = r.CPC;
        impact = r.impact;
        interactiuni = r.interactiuni;
    }

    string get_platformaReclama() const
    {
        return this->platformaReclama;
    }

    double get_CPC()
    {
        return this->CPC;
    }

    int get_impact() const
    {
        return this->impact;
    }

    int get_interactiuni()
    {
        return this->interactiuni;
    }
    void set_platformaReclama(string platformaReclamaI)
    {
        platformaReclama=platformaReclamaI;
    }
    void set_CPC(double CPCI)
    {
        CPC=CPCI;
    }
    void set_impact(int impactI)
    {
        impact=impactI;
    }
    void set_interactiuni(int interactiuniI)
    {
        interactiuni=interactiuniI;
    }
};
istream& operator>>(istream& is, Reclama& r)
{
    string platformaReclamaI;
    double CPCI;
    int impactI, interactiuniI;
    cout<<"------Creare contract------"<<endl;
    cout<<"Platforma pe care se afla reclama(Facebook,Instagram,Tiktok,Google,Youtube): ";
    is >> platformaReclamaI;
    cout<<endl<<"Costul per click: ";
    is >> CPCI;
    cout<<endl<<"Numarul estimativ de oameni care vor vedea reclama: ";
    is >> impactI;
    cout<<endl<<"Numarul estimativ de oameni care o sa interactioneze cu reclama: ";
    is >> interactiuniI;
    cout<<endl;
    r.set_platformaReclama(platformaReclamaI);
    r.set_CPC(CPCI);
    r.set_impact(impactI);
    r.set_interactiuni(interactiuniI);

    return is;
}

class Client
{

private:
     const static int max_serviciiAlese = 5;
    std::string nume;
    array<std::string, max_serviciiAlese> reclameDejaFolosite;
    string email;
    string telefon;
    unique_ptr<std::string[]> serviciuAles;
    bool websiteExistent;
    int capitalReclame;
    int numarReclameDejaFolosite;
public:
    Client(string numeI, string reclameDejaFolositeI[], string emailI, string telefonI, bool websiteExistentI,
           int capitalReclameI, int numarReclameDejaFolositeI)
    {
        nume = numeI;
        for (int i = 0; i < numarReclameDejaFolositeI; i++)
            reclameDejaFolosite[i] = reclameDejaFolositeI[i];
        email = emailI;
        telefon = telefonI;
        websiteExistent = websiteExistentI;
        capitalReclame = capitalReclameI;
        serviciuAles = nullptr;
        numarReclameDejaFolosite = numarReclameDejaFolositeI;
    }

    Client(string numeI, vector<string> reclameDejaFolositeI, string emailI, string telefonI, bool websiteExistentI,
           int capitalReclameI, int numarReclameDejaFolositeI)
    {
        nume = numeI;
        for (int i = 0; i < reclameDejaFolositeI.size(); i++)
            reclameDejaFolosite[i] = reclameDejaFolositeI[i];
        email = emailI;
        telefon = telefonI;
        websiteExistent = websiteExistentI;
        capitalReclame = capitalReclameI;
        serviciuAles = nullptr;
        numarReclameDejaFolosite = numarReclameDejaFolositeI;
    }

    Client(const Client& c) // copy constructor
        : nume(c.nume), email(c.email), telefon(c.telefon), websiteExistent(c.websiteExistent),
          capitalReclame(c.capitalReclame), numarReclameDejaFolosite(c.numarReclameDejaFolosite)
    {
        for (int i = 0; i < c.numarReclameDejaFolosite; i++)
            reclameDejaFolosite[i] = c.reclameDejaFolosite[i];
        serviciuAles = make_unique<string[]>(max_serviciiAlese);
        for (int i = 0; i < max_serviciiAlese; i++)
            serviciuAles[i] = c.serviciuAles[i];
    }
    //getters
    string get_nume()
    {
        return this->nume;
    }
  std::array<std::string, max_serviciiAlese> get_reclameDejaFolosite()
{
    return reclameDejaFolosite;
}
    string get_email()
    {
        return this->email;
    }
    string get_telefon()
    {
        return this->telefon;
    }
    string* get_serviciuAles()
    {
        return serviciuAles.get();
    }
    const static int get_numarMaxServicii()
    {
        return max_serviciiAlese;
    }
    bool get_website()
    {
        return this->websiteExistent;
    }
    int get_capitalReclame()
    {
        return this->capitalReclame;
    }
    int get_numarReclameDejaFolosite()
    {
        return this->numarReclameDejaFolosite;
    }
    void set_nume(string numeI)
    {
        nume=numeI;
    }
    void set_reclameDejaFolosite(string reclameDejaFolositeI[],int numarReclameDejaFolositeI)
    {
        numarReclameDejaFolosite=numarReclameDejaFolositeI;
        for(int i=0; i<numarReclameDejaFolositeI; i++)
            reclameDejaFolosite[i]=reclameDejaFolositeI[i];
    }
    string* alegereServiciu(string serviciu,string reclameDejaFolosite[],int numarReclameDejaFolosite,bool websiteExistent);

    ~Client()
    {

    }
};
string* Client::alegereServiciu(string serviciu, string reclameDejaFolosite[], int numarReclameDejaFolosite, bool websiteExistent)
{


    serviciuAles = make_unique<string[]>(max_serviciiAlese);

    if (serviciu == "Creare Website")
    {
        if (websiteExistent)
        {
            cout << "Clientul are deja website";
            return nullptr;
        }
    }

    for (int i = 0; i < numarReclameDejaFolosite; i++)
    {
        if (reclameDejaFolosite[i] == serviciu)
        {
            cout << "Clientul foloseste deja " << reclameDejaFolosite[i];
            return nullptr;
        }
    }

    return serviciuAles.get();
}



class ClientPremium : public Client //mostenire
{
private:
    const static int max_serviciiAlese = 10;
    string serviciiAlese[max_serviciiAlese];
    int numarServiciiAlese;

public:
    ClientPremium(string numeI, string reclameDejaFolositeI[], string emailI, string telefonI,
                  bool websiteExistentI, int capitalReclameI, int numarReclameDejaFolositeI) :
        Client(numeI, reclameDejaFolositeI, emailI, telefonI, websiteExistentI, capitalReclameI, numarReclameDejaFolositeI)
    {
        numarServiciiAlese = 0;
    }

    void alegeServiciu(string serviciu)
    {
        if (numarServiciiAlese < max_serviciiAlese)
        {
            serviciiAlese[numarServiciiAlese] = serviciu;
            numarServiciiAlese++;
        }
    }

    int get_numarServiciiAlese()
    {
        return numarServiciiAlese;
    }
};

class Website
{

private:
    const static int max_numarFunctionalitati=100;
    int pret,numarPagini,numarFunctionalitati;
    string tipDesign;
    string* functionalitati;
public:
    Website()
    {
        functionalitati = new string[max_numarFunctionalitati];
    };
    //getters website
    int get_pret()
    {
        return pret;
    }
    int get_numarPagini()
    {
        return this->numarPagini;
    }
    int get_numarFunctionalitati()
    {
        return this->numarFunctionalitati;
    }
    string get_tipDesign()
    {
        return tipDesign;
    }
    string* get_functionalitati()
    {
        return functionalitati;
    }

    //setters website
    void set_pret(int pretI)
    {
        pret=pretI;
    }
    void set_numarPagini(int numarPaginiI)
    {
        numarPagini=numarPaginiI;
    }
    void set_numarFunctionalitati(int numarFunctionalitatiI)
    {
        numarFunctionalitati=numarFunctionalitatiI;
    }
    void set_tipDesign(string tipDesignI)
    {
        tipDesign=tipDesignI;
    }
    void set_functionalitati(string functionalitatiI[])
    {
        for (int i=0; i<numarFunctionalitati; i++)
            functionalitati[i]=functionalitatiI[i];
    }
    ~Website()
    {

    }
};


class Serviciu   //clasa de baza abstracta
{
public:
    virtual double calculeazaCost() const = 0;    //metoda pur virtuala + polimorfism la executie in clasele derivate

    virtual ~Serviciu() {};
};

class Logo : public Serviciu
{
public:
    double calculeazaCost() const override
    {
        return 50.0; // prețul pentru Logo
    }
};

class Banner : public Serviciu
{
public:
    double calculeazaCost() const override
    {
        return 1000; // prețul pentru Banner
    }
};

class SEO : public Serviciu
{
public:
    double calculeazaCost() const override
    {
        return 1500; // prețul pentru SEO
    }
};
class SalariuInvalidException : public exception
{
    double m_salariu;
public:
    SalariuInvalidException(double salariu) : m_salariu(salariu) {}

    double getSalariu() const
    {
        return m_salariu;
    }

    const char* what() const noexcept override
    {
        return "Salariu invalid. Trebuie sa fie un numar pozitiv.";
    }



};
template<typename T>
class PachetServicii
{
private:
    static int numarObiecte;
    vector<T*> servicii;

public:
    void adaugaServiciu(T* serviciu)
    {
        if (serviciu == nullptr)
        {
            throw std::invalid_argument("Serviciu nul.");
        }
        servicii.push_back(serviciu);
    }

    double calculeazaCostTotal() const
    {
        double costTotal = 0.0;
        for (const auto& serviciu : servicii)
        {
            costTotal += serviciu->calculeazaCost();
        }
        return costTotal;
    }

    ~PachetServicii()
    {
        for (auto& serviciu : servicii)
        {
            delete serviciu;
        }
    }

    static int getNumarObiecte()
    {
        return numarObiecte;
    }
};

template<typename T>
int PachetServicii<T>::numarObiecte = 0;

class Angajat   //interfata
{
public:
    virtual void adaugaTask(const string& numeTask) = 0;
    virtual void stergeTask(const string& numeTask) = 0;
    virtual void seteazaSalariu(double salariuNou) = 0;
    virtual double getSalariu() const = 0;
    virtual void realizeazaTask(const string& numeTask) = 0 ;
    virtual ~Angajat() {};
};

class AngajatNou : public Angajat
{
    vector<string> tasks;
    double salariu;
public:
    AngajatNou(const vector<string>& initialTasks) : Angajat(), tasks(initialTasks) {}

    virtual void adaugaTask(const string& numeTask) override
    {
        const int MAX_TASK_LENGTH = 50; // lungimea maxima permisa pentru numele unui task
        if (numeTask.length() > MAX_TASK_LENGTH)
        {
            throw length_error("Lungimea numelui task-ului depaseste lungimea maxima permisa.");
        }
        tasks.push_back(numeTask);
    }

    virtual void stergeTask(const string& numeTask) override
    {
        tasks.erase(remove(tasks.begin(), tasks.end(), numeTask), tasks.end());
    }
    virtual void realizeazaTask(const string& numeTask)
    {
        cout << "Angajatul nou a realizat task-ul " << numeTask << endl;
    }
    virtual void seteazaSalariu(double nouSalariu)
    {
        salariu = nouSalariu;
    }
    virtual double getSalariu() const
    {
        return salariu;
    }
    virtual ~AngajatNou()
    {
        cout << "Destructor AngajatNou" << endl;
    }
};

class AngajatVechi : public Angajat
{
    vector<string> tasks;
    double salariu;
public:


    virtual void adaugaTask(const string& numeTask) override
    {
        tasks.push_back(numeTask);
    }

    virtual void stergeTask(const string& numeTask) override
    {
        tasks.erase(remove(tasks.begin(), tasks.end(), numeTask), tasks.end());
    }
    virtual void realizeazaTask(const string& numeTask)
    {
        cout << "Angajatul vechi a realizat task-ul " << numeTask << endl;
    }
    virtual void seteazaSalariu(double nouSalariu) override
    {
        try
        {
            if (nouSalariu <= 0)
            {
                throw SalariuInvalidException(nouSalariu);
            }
            salariu = nouSalariu;
        }
        catch (const SalariuInvalidException& ex)
        {
            cerr << "Eroare: " << ex.what() << " Salariu incercat: " << ex.getSalariu() << endl;
            throw runtime_error("Salariu invalid. Trebuie sa fie un numar pozitiv.");
        }
    }
    static double getSalariuMediu(const vector<AngajatVechi>& angajati)
    {
        double salariuTotal = 0.0;
        for (const auto& angajat : angajati)
        {
            salariuTotal += angajat.getSalariu();
        }
        return salariuTotal / angajati.size();
    }





    virtual ~AngajatVechi()
    {
        cout << "Destructor AngajatVechi" << endl;
    }
};

class Echipa
{
private:
    const static int max_numarMembri=10;
    int numarMembri,numarProiecteInLucru;
    string numeMembri[max_numarMembri],numeEchipa;
    vector <string> tasks;

public:
    Echipa(int numarMembriI,string numeMembriI[],vector <string> tasksI)
    {
        numarMembri=numarMembriI;
        numarProiecteInLucru=0;
        for(int i=0; i<numarMembriI; i++)
            numeMembri[i]=numeMembriI[i];
        for(vector <string>::iterator it=tasksI.begin(); it!=tasksI.end(); it++)
            tasks.push_back(*it);
    };
    int get_numarMembri()
    {
        return this->numarMembri;
    }
    int get_numarPoriecteInLucru()
    {
        return this->numarProiecteInLucru;
    }
    string* get_membri()
    {
        return numeMembri;
    }
    void set_numarMebri(int nrMembri)
    {
        this->numarMembri=nrMembri;
    }
    void set_adaugaProiecteInLucru()
    {
        this->numarProiecteInLucru+=1;
    }
    void set_membri(string membriNou[],int nrMembri)
    {
        this->numarMembri=nrMembri;
        for (int i=0; i<nrMembri; i++)
            numeMembri[i]=membriNou[i];
    }



};


class Contract
{
protected:
    const static int max_numarServicii=50;
    vector<string> servicii;
    int durataLuni;
    int pretTotal;
    int procentDinIncasari;
    int numarServicii;
    string dataInceperii;
    string dataFinalizarii;
    Echipa* echipa;

public:
    Contract(vector<string> serviciiI, int durataLuniI, int pretTotalI, int procentDinIncasariI,
             int numarServiciiI, string dataInceperiiI, string dataFinalizariiI, Echipa* echipaI)
        : servicii(serviciiI), durataLuni(durataLuniI), pretTotal(pretTotalI), procentDinIncasari(procentDinIncasariI),
          numarServicii(numarServiciiI), dataInceperii(dataInceperiiI), dataFinalizarii(dataFinalizariiI), echipa(echipaI)
    {}
    int get_durataLuni()
    {
        return this->durataLuni;
    }

    operator double() const
    {
        return static_cast<double>(procentDinIncasari) / 100.0;
    }
    double get_procentDinIncasari()
    {
        return static_cast<double>(procentDinIncasari) / 100.0;
    }
    int get_pretTotal()
    {
        return this->pretTotal;
    }

    int get_numarServicii()
    {
        return this->numarServicii;
    }
    string get_dataInceperii()
    {
        return dataInceperii;
    }
    string get_dataFinalizarii()
    {
        return dataFinalizarii;
    }

    void set_durataLuni(int durataLuniI)
    {
        durataLuni=durataLuniI;
    }
    void set_procentDinIncasari(double procentDinIncasariI)
    {
        procentDinIncasari=procentDinIncasariI*100;
    }
    void set_pretTotal (int pretTotalI,Client client)
    {
        if(client.get_capitalReclame()<pretTotalI)
            cout<<"Contractul depaseste capitalul pentru reclamei al Clientului";
        else
            pretTotal=pretTotalI;
    }
    void set_numarServicii (int numarServiciiI)
    {
        numarServicii=numarServiciiI;
        numarServicii=numarServiciiI;
    }
    void set_dataInceperii (string dataInceperiiI)
    {
        dataInceperii=dataInceperiiI;

    }
    void set_dataFinalizarii (string dataFinalizariiI)
    {
        dataFinalizarii=dataFinalizariiI;
    }
    void set_echipa(Echipa* echipaI)
    {
        echipa=echipaI;
    }

    Contract operator+(const Contract& other) const
    {
        int totalDurata = this->durataLuni + other.durataLuni;
        int totalPret = this->pretTotal + other.pretTotal;
        int totalNumarServicii = this->numarServicii + other.numarServicii;
        double totalProcent = this->procentDinIncasari + other.procentDinIncasari;

        vector <string> totalServicii;

        for (int i = 0; i < this->numarServicii; i++)
        {
            totalServicii.push_back(this->servicii[i]);
        }
        for (int i = 0; i < other.numarServicii; i++)
        {
            totalServicii.push_back(other.servicii[i]);
        }

        return Contract(totalServicii, totalDurata, totalPret, totalProcent, totalNumarServicii,"", "",NULL);
    }


};

ostream& operator<<(ostream& out,  Contract& contract) //supraincarcare "<<"
{
    out<< "Durata contractului: "<<contract.get_durataLuni()<<" luni"<<endl;
    out<< "Procentul pe care il ia firma din incasari: "<<contract.get_procentDinIncasari()<<"%"<<endl;
    out<< "Valoarea totala a contractului :" << contract.get_pretTotal()<<endl;
    out<< "Numarul total de servicii pe care le include contractul: " << contract.get_numarServicii()<<endl;
    out<< "Data de incepere a contractului: "<<contract.get_dataInceperii()<<endl;
    out<< "Data de terminare a contractului: " << contract.get_dataFinalizarii()<<endl;
    return out;
}


class ClientContract : public Client, protected Contract //mostenire multipla
{
public:
    ClientContract(string numeI, vector<string> reclameDejaFolositeI, string emailI, string telefonI, bool websiteExistentI,
                   int capitalReclameI, int numarReclameDejaFolositeI, vector<string> serviciiI, int durataLuniI, int pretTotalI,
                   int procentDinIncasariI, int numarServiciiI, string dataInceperiiI, string dataFinalizariiI, Echipa* echipaI)
        : Client(numeI, reclameDejaFolositeI, emailI, telefonI, websiteExistentI, capitalReclameI, numarReclameDejaFolositeI),
          Contract(serviciiI, durataLuniI, pretTotalI, procentDinIncasariI, numarServiciiI, dataInceperiiI, dataFinalizariiI, echipaI)
    {
    }

    using Contract::operator+;


    vector<string> listaServiciiAlese()
    {
        vector<string> lista;

        for (const auto& serviciu : servicii)
        {
            lista.push_back(serviciu);
        }

        auto serviciiClient = get_serviciuAles();
        if (serviciiClient != nullptr)
        {
            for (int i = 0; i < get_numarMaxServicii(); i++)
            {
                if (!serviciiClient[i].empty())
                {
                    lista.push_back(serviciiClient[i]);
                }
            }
        }

        return lista;
    }

    // Metoda care returneaza numarul total de servicii alese de client
    int numarTotalServiciiAlese()
    {
        return numarServicii + get_numarReclameDejaFolosite();
    }
};
class Agentie
{
private:
    static const int max_numarContracte=10;
    static const int max_numarServicii=6;
    string nume;
    Reclama* servicii[max_numarServicii];
    int numarServiciiOferite;
    int numarContracteActive;
    Contract* contracteActive[max_numarContracte];
    double incasari;
public:
    Agentie(string numeI)
    {
        nume = numeI;
        numarServiciiOferite = 0;
        numarContracteActive=0;
        incasari=0;

    };
    string get_nume()
    {
        return this->nume;
    }

    int get_numarServicii()
    {
        return this->numarServiciiOferite;
    }
    string get_incasari()
    {
        return to_string(this->incasari) + " Lei";
    }
    int get_numarContracteActive()
    {
        return numarContracteActive;
    }
    void set_nume(string numeNou)
    {
        nume=numeNou;
    }
    void set_numarServiciiOferite(int numarServiciiOferiteI)
    {
        this->numarServiciiOferite=numarServiciiOferiteI;
    }

    void adaugareContract(Contract contract)
    {
        if(numarContracteActive<max_numarContracte)
        {
            numarContracteActive+=1;
            contracteActive[numarContracteActive]=&contract;
            incasari+=contract.get_procentDinIncasari() * contract.get_pretTotal();
        }
        else
            cout<<"ERROR:Agentia are un numar prea mare de contracte active si nu poate face fata";

    }
    void afiseazaContracteActive()
    {
        if(numarContracteActive == 0)
        {
            cout << "Nu exista contracte active la agentia " << endl;
        }
        else
        {
            cout << "Contracte active la agentia " << nume << ":" << endl;
            for(int i = 1; i <= numarContracteActive; i++)
            {
                cout << "Contract " << i << ":" << endl;

                if(contracteActive[i] == nullptr)
                {
                    cout << "Eroare: contractul nu a fost initializat corect" << endl;
                    continue;
                }

                cout << "Pret total: " << contracteActive[i]->get_pretTotal() << " Lei" << endl;
                cout<< "Data inceperii: "<< contracteActive[i]->get_dataInceperii()<< endl;
                cout << "Data incheierii: " << contracteActive[i]->get_dataFinalizarii() << endl;
            }
        }
    }

    void adaugareServiciu(Reclama reclama)
    {

        string platformaReclama=reclama.get_platformaReclama();
        bool ok=true;
        for(int i=1; i<=numarServiciiOferite; i++)
            if(servicii[i]->get_platformaReclama()==platformaReclama)
            {
                servicii[i]=&reclama;
                ok=false;
            }
        if(ok)
        {

            if(numarServiciiOferite<max_numarServicii)
            {
                numarServiciiOferite+=1;

                servicii[numarServiciiOferite]=&reclama;
            }
            else
                cout<<"ERROR:Numarul maxim de servicii este depasit";
        }
    }
    void afisareServicii()
    {
        if(numarServiciiOferite == 0)
        {
            cout << "Nu exista servicii oferite la agentia " << nume << endl;
        }
        else
        {
            cout << "Servicii oferite de agentia " << nume << ":" << endl;
            for(int i = 1; i <= numarServiciiOferite; i++)
            {
                cout << "Serviciu " << i << ":" << endl;
                cout << "Platforma: " << servicii[i]->get_platformaReclama() << endl;
                cout << "Cost per click: " << servicii[i]->get_CPC() << " $" << endl;
                cout << "Impact: " << servicii[i]->get_impact() << endl;
                cout << "Interactiuni: " << servicii[i]->get_interactiuni() << endl;
            }
        }
    }

};

bool comparareImpact(const Reclama& r1, const Reclama& r2)
{
    return r1.get_impact() < r2.get_impact();
}

int main()
//lista Reclame="Instagram Ads","Facebook Ads","Google Ads","Creare Website","Youtube Ads"
{
    string reclame[] = {"Instagram Ads", "Facebook Ads"};
    Angajat* a = new AngajatNou({"Creare logo", "Creare Reclama", "Meeting echipa"});
    a->adaugaTask("Creare website");
    a->adaugaTask("Optimizare SEO");
    a->stergeTask("Creare Website");
    a->seteazaSalariu(2000);
    delete a;

    Angajat* angajat = new AngajatNou({"Creare banner", "Creare reclama Google Ads"});
    angajat->seteazaSalariu(1000);


    //downcasting
    AngajatNou* angajatNou = dynamic_cast<AngajatNou*>(angajat);
    if (angajatNou != nullptr)
    {
        cout << "Salariul angajatului nou este: " << angajatNou->getSalariu() << endl;
    }
    else
    {
        cout << "Nu am putut converti pointerul" << endl;
    }

    delete angajat;
    Serviciu* serviciu = new Logo(); // se creează un obiect de tip Logo și se stochează adresa lui într-un pointer de tip Serviciu
    double cost = serviciu->calculeazaCost(); // se apelează metoda calculeazaCost() prin intermediul pointerului de tip Serviciu, dar se va apela implementarea din clasa Logo, deoarece obiectul din spate este de tip Logo
    PachetServicii<Logo> pachet;
    pachet.adaugaServiciu(new Logo());

    double costTotal = pachet.calculeazaCostTotal(); // se face apel dinamic la metoda calculeazaCost() pentru fiecare obiect din vectorul servicii, indiferent de tipul său
    Logo* logo = new Logo();
    Serviciu* serviciuLogo = logo;
    Banner banner;
    Serviciu& serviciuBanner = banner;
    AngajatNou angajatNou2({ "Cercetare concurenta Google Ads", "Realizare design p" });
    try
    {
        angajatNou2.adaugaTask("acesta este un task cu o lungime foarte mare care depaseste lungimea maxima permisa");
    }
    catch (const  exception& e)
    {
        cerr << "Eroare: " << e.what() << endl;
    }
PachetServicii<Logo> pachet1; // Crearea primului pachet de servicii pentru tipul Logo
    PachetServicii<Banner> pachet2; // Crearea celui de-al doilea pachet de servicii pentru tipul Banner

    std::cout << "Numar obiecte PachetServicii: " << PachetServicii<Logo>::getNumarObiecte() << std::endl;

    // ...

    PachetServicii<SEO> pachet3; // Crearea celui de-al treilea pachet de servicii pentru tipul SEO

    pachet3.adaugaServiciu(new SEO());
    pachet3.adaugaServiciu(new SEO());
    pachet3.adaugaServiciu(new SEO());

    std::cout << "Costul total al pachetului de servicii este: " << pachet3.calculeazaCostTotal() << std::endl;
    vector <string> reclamevect= {"Instagram Ads", "Facebook Ads"};
    Agentie agentie("CreativeAgency");
    Client client("FirmaSRL", reclame, "info@firmasrl.com", "0753616640", true, 300000, 2);
    client.alegereServiciu("Youtube Ads", reclame, 2, false);
    Reclama reclama1("Facebook", 0.20, 1100, 80);
    Reclama reclama2("Youtube", 0.10, 55500, 400);
    Reclama reclama3("Instagram", 0.12, 18000, 160);
    Reclama reclama4(reclama1);
    Reclama reclama5;
    cin >> reclama5;
    agentie.adaugareServiciu(reclama1);
    agentie.adaugareServiciu(reclama2);
    agentie.adaugareServiciu(reclama3);
    agentie.adaugareServiciu(reclama4);
    agentie.adaugareServiciu(reclama5);
    agentie.afisareServicii();
    string numeMembrii[] = {"Ion", "Maria", "Andrei"};
    Echipa echipa1(3, numeMembrii,reclamevect);
    Contract contract1(reclamevect, 2, 50000, 4, 1, "02/10/2022", "02/12/2022", &echipa1);
    Contract contract2(reclamevect, 2, 25000, 6, 1, "04/01/2023", "04/04/2023", &echipa1);
    Contract contract3(reclamevect, 2, 34000, 7, 1, "12/03/2022", "12/06/2022", &echipa1);
    contract1.set_echipa(&echipa1);
    agentie.adaugareContract(contract1);
    agentie.adaugareContract(contract2);
    agentie.adaugareContract(contract3);
    cout << "Numarul de contracte active: " << agentie.get_numarContracteActive() << endl;
    agentie.afiseazaContracteActive();
    agentie.set_numarServiciiOferite(3);
    agentie.afisareServicii();
    cout << agentie.get_incasari() << endl;
 std::vector<Reclama> reclameSortate;

    Reclama r1("Facebook", 0.5, 100, 10);
    Reclama r2("Instagram", 0.4, 200, 20);
    Reclama r3("TikTok", 0.6, 150, 15);

    reclameSortate.push_back(r1);
    reclameSortate.push_back(r2);
    reclameSortate.push_back(r3);

    std::cout << "Reclamele inainte de sortare:" << std::endl;
    for (const auto& reclama : reclameSortate)
    {
        std::cout << reclama.get_platformaReclama() << " - Impact: " << reclama.get_impact() << std::endl;
    }

    std::sort(reclameSortate.begin(), reclameSortate.end(), comparareImpact);

    std::cout << std::endl << "Reclamele dupa sortare:" << std::endl;
    for (const auto& reclameSortata : reclameSortate)
    {
        std::cout << reclameSortata.get_platformaReclama() << " - Impact: " << reclameSortata.get_impact() << std::endl;
    }

    return 0;
}
