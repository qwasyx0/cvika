#ifndef __MATICE
#define __MATICE
#endif // !__MATICE

#include <stdexcept>
#include <iostream>
#include <string>

template<typename T>
struct Matice
{
public:
	Matice(int radky, int sloupce) {
		this->pocetRadku = radky;
		this->pocetSloupcu = sloupce;
		this->prvky = new T * [pocetRadku];

		for (int i = 0; i < radky; i++)
		{
			prvky[i] = new T[pocetSloupcu];
			for (int j = 0; j < sloupce; j++) {
				prvky[i][j] = 0;
			}
		}
	}

	Matice(const Matice<T>& m) {
		this->pocetRadku = m.pocetRadku;
		this->pocetSloupcu = m.pocetSloupcu;
		this->prvky = new T * [pocetRadku];

		for (int i = 0; i < this->pocetRadku; i++)
		{
			this->prvky[i] = new T[pocetSloupcu];
			for (int j = 0; j < this->pocetSloupcu; j++) {
				this->prvky[i][j] = m.prvky[i][j];
			}
		}
	}

	~Matice() {
		for (int i = 0; i < pocetRadku; i++)
		{
			delete[] prvky[i];
		}

		delete[] prvky;
	}

	void Nastav(int radek, int sloupec, T hodnota);
	void NastavZ(T* pole);
	T& Dej(int radek, int sloupec) const;
	const T& Dej(int radek, int sloupec);

	template<typename R>
	Matice<R> Pretypuj() const;

	Matice Transpozice() const;
	Matice Soucin(const Matice& m) const;
	Matice Soucin(T skalar) const;
	Matice Soucet(const Matice& m) const;
	Matice Soucet(T skalar) const;

	bool JeShodna(const Matice& m) const;

	void Vypis() const;
private:
	T** prvky;
	int pocetRadku;
	int pocetSloupcu;
};

template<typename T>
void Matice<T>::Nastav(int radek, int sloupec, T hodnota) {
	if (radek < 0 || radek > this->pocetRadku || sloupec < 0 || sloupec > this->pocetSloupcu)
	{
		throw std::exception("Neplatny index");
	}

	prvky[radek][sloupec] = hodnota;
}

template<typename T>
void Matice<T>::NastavZ(T* pole) {
	for (int i = 0; i < this->pocetRadku; i++)
	{
		for (int j = 0; j < this->pocetSloupcu; j++)
		{
			prvky[i][j] = pole[(i * this->pocetSloupcu) + j];
		}
	}
}

template<typename T>
T& Matice<T>::Dej(int radek, int sloupec) const {
	if (radek < 0 || radek > this->pocetRadku || sloupec < 0 || sloupec > this->pocetSloupcu)
	{
		throw std::exception("Neplatny index");
	}

	return prvky[radek][sloupec];
}

template<typename T>
const T& Matice<T>::Dej(int radek, int sloupec) {
	if (radek <= 0 || radek > this->pocetRadku || sloupec <= 0 || sloupec > this->pocetSloupcu)
	{
		throw std::out_of_range("Neplatny index");
	}

	return prvky[radek][sloupec];
}

template<typename T>
template<typename R>
Matice<R> Matice<T>::Pretypuj() const {
	Matice<R> novaMatice{ this->pocetRadku, this->pocetSloupcu };

	for (int i = 0; i < this->pocetRadku; i++)
	{
		for (int j = 0; j < this->pocetSloupcu; j++)
		{
			novaMatice.Nastav(i, j, static_cast<R>(Dej(i, j)));
		}
	}
	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Transpozice() const {
	Matice<T> novaMatice{ this->pocetSloupcu, this->pocetRadku };
	for (int i = 0; i < novaMatice.pocetRadku; i++)
	{
		for (int j = 0; j < novaMatice.pocetSloupcu; j++)
		{
			novaMatice.prvky[i][j] = prvky[j][i];
		}
	}
	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Soucin(const Matice& m) const {
	if (this->pocetSloupcu != m.pocetRadku)
	{
		throw std::invalid_argument("Pocet sloupcu prvni matice musi byt stejny jako pocet radku druhe");
	}
	Matice<T> novaMatice{ this->pocetRadku, m.pocetSloupcu };

	for (int i = 0; i < pocetRadku; i++)
	{
		for (int j = 0; j < m.pocetSloupcu; j++)
		{
			T pom = 0;
			for (int k = 0; k < m.pocetRadku; k++)
			{
				pom += prvky[i][k] * m.prvky[k][j];
			}
			novaMatice.prvky[i][j] = pom;
		}
	}

	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Soucin(T skalar) const {
	Matice<T> novaMatice{ this->pocetRadku, this->pocetSloupcu };
	for (int i = 0; i < pocetRadku; i++)
	{
		for (int j = 0; j < pocetSloupcu; j++)
		{
			novaMatice.prvky[i][j] = prvky[i][j] * skalar;
		}
	}
	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Soucet(const Matice& m) const {
	if (this->pocetRadku != m.pocetRadku || this->pocetSloupcu != m.pocetSloupcu)
	{
		throw std::invalid_argument("Matice musi mit stejne rozmery...");
	}

	Matice<T> novaMatice{ this->pocetRadku, this->pocetSloupcu };

	for (int i = 0; i < pocetRadku; i++)
	{
		for (int j = 0; j < pocetSloupcu; j++)
		{
			novaMatice.prvky[i][j] = m.prvky[i][j] + prvky[i][j];
		}
	}
	return novaMatice;
}

template<typename T>
Matice<T> Matice<T>::Soucet(T skalar) const {
	Matice<T> novaMatice{ this->pocetRadku, this->pocetSloupcu };

	for (int i = 0; i < pocetRadku; i++)
	{
		for (int j = 0; j < pocetSloupcu; j++)
		{
			novaMatice.prvky[i][j] = prvky[i][j] + skalar;
		}
	}

	return novaMatice;
}

template<typename T>
bool Matice<T>::JeShodna(const Matice& m) const {
	if (this->pocetRadku != m.pocetRadku || this->pocetSloupcu != pocetSloupcu)
		return false;

	for (int i = 0; i < this->pocetRadku; i++)
	{
		for (int j = 0; j < this->pocetSloupcu; j++) {
			if (prvky[i][j] != m.prvky[i][j])
			{
				return false;
			}
		}
	}

	return true;
}


template<typename T>
void Matice<T>::Vypis() const {
	for (int i = 0; i < this->pocetRadku; i++)
	{
		for (int j = 0; j < this->pocetSloupcu; j++) {
			std::cout << std::to_string(prvky[i][j]) << "\t";
		}

		std::cout << std::endl;
	}
}
