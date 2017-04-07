#ifndef GARDUINO_H
#define GARDUINO_H


class Sensors {
public:
	int getValue(); // demande la valeur d un senseur et renvoie cette valeur entiere
protected:
private:




};

class Relays {
	public:
		void setValue(bool position);// recoit une valeur booleenne qui controle la position du relai (ouvert/ferme) et ne retourne rien
	protected:
	private:



};






#endif // !GARDUINO_H