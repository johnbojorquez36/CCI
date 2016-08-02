#include <vector>
#include <climits>

enum class Suit {Club, Diamond, Heart, Spade};

class Card {
protected:
  int faceValue;
  Suit suit;

public:
  Card(int faceValue, Suit suit);
  /* Cards for different games will have different values */
  virtual int getValue() = 0;
  Suit getSuit() { return suit; }
};

class Hand {
  int size = 0;
  std::vector<Card*> cards;

public:
  /* Different games tally the score differently */
  virtual int score() = 0;
  int getSize() { return size; }
  Card* getCard(int i);
  void removeCard(int i);
};

class Deck {
  std::vector<Card*> cards;
  int nextToDeal = 0;

public:
  Deck(std::vector<Card>);
  void shuffle();
  Card* dealCard();
  std::vector<Card> dealCards(int n);
  int cardsDealt() { return nextToDeal; };
};


class BlackJackCard : Card {
public:
  int value() {
    if (faceValue >= 11 && faceValue <= 13) return 10;
    return faceValue;
  }
  
  int minValue() {
    return value();
  }

  int maxValue() {
    if (faceValue == 1) return 11;
    return value();
  }
};

class BlackJackHand : Card {
public:
  int score() {
    int bestScore = INT_MAX;
    std::vector<int> scores = possibleScores();
    for (int score : scores) {
      if ((bestScore > 21 && score < bestScore) ||
	  (bestScore < 21 && score <= 21 && score > bestScore)) {
	bestScore = score;
      }
    }
    return bestScore;
  }

  std::vector<int> possibleScores();
};
