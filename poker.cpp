#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define T 10
#define J 11
#define Q 12
#define K 13
#define A 14

/*
 *PC/UVa IDs: 110202/10315, Popularity: C, Success rate: average Level: 2
    A poker deck contains 52 cards. Each card has a suit of either clubs, diamonds, hearts,
    or spades (denoted C, D, H, S in the input data). Each card also has a value of either 2
    through 10, jack, queen, king, or ace (denoted 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A). For
    scoring purposes card values are ordered as above, with 2 having the lowest and ace the
    highest value. The suit has no impact on value.
    A poker hand consists of five cards dealt from the deck. Poker hands are ranked by
    the following partial order from lowest to highest.
    High Card. Hands which do not fit any higher category are ranked by the value of
    their highest card. If the highest cards have the same value, the hands are ranked
    by the next highest, and so on.
    Pair. Two of the five cards in the hand have the same value. Hands which both contain
    a pair are ranked by the value of the cards forming the pair. If these values are
    the same, the hands are ranked by the values of the cards not forming the pair,
    in decreasing order.
    Two Pairs. The hand contains two different pairs. Hands which both contain two pairs
    are ranked by the value of their highest pair. Hands with the same highest pair
    are ranked by the value of their other pair. If these values are the same the hands
    are ranked by the value of the remaining card.
    Three of a Kind. Three of the cards in the hand have the same value. Hands which
    both contain three of a kind are ranked by the value of the three cards.
    Straight. Hand contains five cards with consecutive values. Hands which both contain
    a straight are ranked by their highest card.
    Flush. Hand contains five cards of the same suit. Hands which are both flushes are
    ranked using the rules for High Card.
    Full House. Three cards of the same value, with the remaining two cards forming a
    pair. Ranked by the value of the three cards.
    Four of a Kind. Four cards with the same value. Ranked by the value of the four
    cards.
    Straight Flush. Five cards of the same suit with consecutive values. Ranked by the
    highest card in the hand.
    Your job is to compare several pairs of poker hands and to indicate which, if either,
    has a higher rank.

    Input
    The input file contains several lines, each containing the designation of ten cards: the
    first five cards are the hand for the player named “Black” and the next five cards are
    the hand for the player named “White”.

    Output
    For each line of input, print a line containing one of the following:
    Black wins.
    White wins.
    Tie.

 */
enum handRank {HCard, Pair, TPair, ThAKind, Straight, Flush, FHouse, FourAKind, SFlush};
char suits[5] = "CDHS";
class aCard{
    public:
        int rank;
        char suit;
        void setRank(int tempRank){
            rank = tempRank;
        }
        void setRank(char tempRank){
            switch(tempRank){
                case '2':
                    rank=2;
                    break;
                case '3':
                    rank = 3;
                    break;
                case '4':
                    rank=4;
                    break;
                case '5':
                    rank = 5;
                    break;
                case '6':
                    rank=6;
                    break;
                case '7':
                    rank = 7;
                    break;
                case '8':
                    rank=8;
                    break;
                case '9':
                    rank = 9;
                    break;
                case 'T':
                    rank = 10;
                    break;
                case 'J':
                    rank = 11;
                    break;
                case 'Q':
                    rank = 12;
                    break;
                case 'K':
                    rank = 13;
                    break;
                case 'A':
                    rank = 14;
                    break;
                default:
                    printf("Invalid Rank is entered");
            }
        }
        void setSuit(char tempSuit){
            suit = tempSuit;
        }
        int getRank(){
            return rank;
        }
        char getSuit(){
            return suit;
        }
};
class aHand{
    public:
        aCard cards[5];
        void readHand(){
            char c, tempSuit;
            int count;
            count = 0;
            while((c = getchar())!='\n' && count < 5 ){
                if(c != ' '){
                    cards[count].setRank(c);
                    tempSuit = getchar();
                    cards[count].setSuit(tempSuit);
                    count++;
                }
            }

        }
        void sortRank(){
            for(int i=0; i<5; i++){
                for(int j=i+1; j<5; j++){
                    if(cards[i].getRank()<cards[j].getRank()){
                        int temp = cards[i].rank;
                        char tempSuit = cards[i].suit;
                        cards[i].setRank(cards[j].rank);
                        cards[i].setSuit(cards[j].suit);
                        cards[j].setRank(temp);
                        cards[j].setSuit(tempSuit);
                    }
                }
            }
        }
/**************** Flush   ******************/
        bool checkFlush(){
            sortRank();
            int count;
            char temp;
            /** Checking for 4 Suits   ***/
            for(int i=0; i<4; i++){
                temp = suits[i];
                count = 0;
                for(int j=0; j<5; j++){
                    if(cards[j].getSuit()==temp){
                        count++;
                    }
                }
                if(count == 5)
                    return true;
            }
            return false;
        }
/**************  Four of A Kind    *************/
        int checkFourAKind(){
            int count;
            int temp;
            for(int i=2;i<=14;i++){
                temp = i;
                count = 0;
                for(int j=0;j<5;j++){
                    if(cards[j].getRank()==temp){
                        count++;
                    }
                }
                if(count == 4)
                    return temp;
            }
            return 0;
        }
        int checkStraight(){
            sortRank();
            int count=0;
            for(int i=0;i<4;i++){
                if(cards[i+1].getRank()-cards[i].getRank()==1)
                    count++;
            }
            if(count == 5)
                return cards[4].getRank();
            return 0;
        }
/**************  Royal Flush      ******************/
        bool checkRFlush(){
            sortRank();
            if(checkFlush()){
                if(checkStraight()==14)
                    return true;
            }
            return false;
        }

/************* Pair      ***********************/
        int checkPair(){
            int count;
            int temp;
            for(int i=2;i<=14;i++){
                temp = i;
                count = 0;
                for(int j=0;j<5;j++){
                    if(cards[j].getRank()==temp)
                        count++;
                    if(count == 2)
                        return temp;
                }
            }
            return 0;
        }
/************ Three Of A Kind   *************/
        int checkThreeOfAKind(){
            int count;
            int temp;
            for(int i=2;i<=14;i++){
                temp = i;
                count = 0;
                for(int j=0;j<5;j++){
                    if(cards[j].getRank()==temp)
                        count++;
                    if(count == 3)
                        return temp;
                }
            }
            return 0;
        }
/********* Full House      **************/
        bool checkFullHouse(){
            if(checkThreeOfAKind() && checkPair())
                return true;
            return false;
        }

/********   Two Pair     **************/
        int checkTwoPair(){
            int count1,count2;
            int temp1,temp2;
            for(int i=2;i<=14;i++){
                temp1 = i;
                count1 = 0;
                for(int j=0; j<5; j++){
                    if(cards[j].getRank()==temp1)
                        count1++;
                    if(count1 == 2){
                        for(int k=0; k<5;k++){
                            temp2 = k;
                            if(k!=temp1){
                                if(cards[k].getRank()==temp2)
                                    count2++;
                                if(count2==2)
                                    return ((temp1>temp2)?temp1:temp2);
                            }
                        }
                    }
                }
            }
            return false;
        }

        int checkHighestNo(){
            sortRank();
            int max = 1;
            for(int i=0;i<5;i++){
                if(cards[i].getRank() > max)
                    max = cards[i].getRank();
            }
            return max;
        }
        int evaluate(){
            if(checkRFlush())
                return 9;
            else if(checkFourAKind())
                return 8;
            else if(checkFullHouse())
                return 7;
            else if(checkStraight())
                return 6;
            else if(checkStraight())
                return 5;
            else if(checkThreeOfAKind())
                return 4;
            else if(checkTwoPair())
                return 3;
            else if(checkPair())
                return 2;
            else
                return 1;
        }
        void printHand(){
            for(int i=0;i<5;i++){
                printf("%d%c\t",cards[i].rank,cards[i].suit);
            }
        }
};

void judge(aHand &a, aHand&b){
    int aScore, bScore;
    aScore = a.evaluate();
    bScore = b.evaluate();
    if(aScore > bScore)
        printf("Black wins");
    else if(aScore > bScore)
        printf("White wins");
    else{
        int key = aScore;
        switch(key){
            case 9:
                printf("Tie");
                break;
            case 8:
                if(a.checkFourAKind() > b.checkFourAKind())
                    printf("Black wins");
                else if(a.checkFourAKind() < b.checkFourAKind())
                    printf("White wins");
                else
                    printf("Tie");
                break;
            case 7:
                if(a.checkThreeOfAKind() > b.checkThreeOfAKind())
                    printf("Black wins");
                else if(a.checkThreeOfAKind() < b.checkThreeOfAKind())
                    printf("White wins");
                else{
                    if(a.checkPair() > b.checkPair())
                        printf("Black wins");
                    else if(a.checkPair() < b.checkPair())
                        printf("White wins");
                    else
                        printf("Tie");
                }
                break;
            case 6:
            case 5:
                if(a.checkHighestNo() > b.checkHighestNo())
                    printf("Black wins");
                else if(a.checkHighestNo() < b.checkHighestNo())
                    printf("White wins");
                else
                    printf("Tie");
                break;
            case 4:
                if(a.checkThreeOfAKind() > b.checkThreeOfAKind())
                    printf("Black wins");
                else if(a.checkThreeOfAKind() < b.checkThreeOfAKind())
                    printf("White wins");
                else
                    printf("Tie");
                break;
            case 3:
                if(a.checkTwoPair() > b.checkTwoPair())
                    printf("Black wins");
                else if(a.checkTwoPair() < b.checkTwoPair())
                    printf("White wins");
                break;
            case 2:
                if(a.checkPair() > b.checkPair())
                    printf("Black wins");
                else if(a.checkPair() < b.checkPair())
                    printf("White wins");
                else
                    printf("Tie");
                break;
            case 1:
                a.sortRank();
                b.sortRank();
                for(int i=4; i>=0; i--){
                    if(a.cards[i].getRank() > b.cards[i].getRank()){
                        printf("Black wins");
                        return;
                    }
                    else if(a.cards[i].getRank() < b.cards[i].getRank()){
                        printf("White wins");
                        return;
                    }
                }
                printf("Tie");
                break;
        }
    }

}
int main(){
    aHand bl,wh;
    bl.readHand();
    wh.readHand();
    judge(bl,wh);
    return 0;

}
