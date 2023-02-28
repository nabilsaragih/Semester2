#include <iostream>
using namespace std;

class Suhu {
    private:
        float suhuCelcius;
        float suhuReamur;
        float suhuFahrenheit;
        float suhuKelvin;

    public:
        void setSuhu(float temperature) {
            suhuCelcius = temperature;
            suhuReamur = temperature;
            suhuFahrenheit = temperature;
            suhuKelvin = temperature;
        }

        auto getSuhu() { 
            struct Hasil {
                float suhuCelciusKeReamur;
                float suhuCelciusKeFahrenheit;
                float suhuCelciusKeKelvin;
                float suhuReamurKeCelcius;
                float suhuReamurKeFahrenheit;
                float suhuReamurKeKelvin;
                float suhuFahrenheitKeCelcius;
                float suhuFahrenheitKeReamur;
                float suhuFahrenheitKeKelvin;
                float suhuKelvinKeCelcius;
                float suhuKelvinKeFahrenheit;
                float suhuKelvinKeReamur;
            };

            return Hasil{
                suhuCelcius + (4/5), ((suhuCelcius * (9/5)) + 32), suhuCelcius + 273,
                suhuReamur * (5/4), (suhuReamur * (9/4)) + 32, (suhuReamur * (5/4)) + 273,
                (suhuFahrenheit - 32) * (5/9), (suhuFahrenheit - 32) * (4/9), ((suhuFahrenheit - 32) * (5/9)) + 273,
                suhuKelvin - 273, ((suhuKelvin - 273) * (9/5)) + 32, (suhuKelvin - 273) * (4/5)
            }; 
        }
};

int main() {
    Suhu cobacelcius;
    cobacelcius.setSuhu(36);
    cout << cobacelcius.getSuhu().suhuCelciusKeReamur << endl;
    cout << cobacelcius.getSuhu().suhuCelciusKeFahrenheit << endl;
    cout << cobacelcius.getSuhu().suhuCelciusKeKelvin << endl;

    Suhu cobareamur;
    cobareamur.setSuhu(76);
    cout << cobareamur.getSuhu().suhuReamurKeCelcius << endl;
    cout << cobareamur.getSuhu().suhuReamurKeFahrenheit << endl;
    cout << cobareamur.getSuhu().suhuReamurKeKelvin << endl;
}