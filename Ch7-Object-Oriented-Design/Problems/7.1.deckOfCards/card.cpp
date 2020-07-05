#include <iostream>

class Suit
{
	public:
		enum { Clubs, Diamond, Heart, Spade };
		int getValue() { return value; }
		static Suit getSuitFromValue(int value) { }

	private:
		int value;
		Suit(int v) { value = v; }
};

class Card
{
	public:
		Card(int c, Suit s) {
			faceValue = c;
			suit = s;
		}
		virtual int value();
		
		Suit suit() { return suit; }

		bool isAvailable() { return available; }
		void markUnavailable() { available = false; }
		void markAvailable() { available = true; }

	protected:
		int faceValue;
		Suit suit;

	private:
		bool available = true;

};

template<typename T> 
T Deck 
{
	public:
		Deck() { }
		void setDeckOfCards(std::vector<T> deckOfCards) {
			cards = deckOfCards;
		}
		void shuffle() { }
		int remainingCards() { return cards.size() - dealtIndex; }
		std::vector<T> dealHand(int number) { }
		T dealCard() { }

	private:
		std::vector<T> cards;
		int dealtIndex = 0; // marks first undealt card
}


int main()
{

	return 0;
}
