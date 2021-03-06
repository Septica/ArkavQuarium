#include "Aquarium.hpp"

Aquarium::Aquarium(int _sizeX, int _sizeY, int _money, int _eggPrice) : sizeX(_sizeX), sizeY(_sizeY) {
    setGameTime(0);
    add(Snail(*this));
    setMoney(_money);
    setEgg(0);
    setEggPrice(_eggPrice);
}

int Aquarium::getSizeX() const {
    return sizeX;
}
int Aquarium::getSizeY() const {
    return sizeY;
}
int Aquarium::getGameTime() const {
    return gameTime;
}
LinkedList<Guppy>& Aquarium::getGuppies() {
    return guppies;
}
LinkedList<Piranha>& Aquarium::getPiranhas() {
    return piranhas;
}
LinkedList<Snail>& Aquarium::getSnails() {
    return snails;
}
LinkedList<Food>& Aquarium::getFoods() {
    return foods;
}
LinkedList<Coin>& Aquarium::getCoins() {
    return coins;
}
int Aquarium::getMoney() const {
    return money;
}
int Aquarium::getEgg() const {
    return egg;
}
int Aquarium::getEggPrice() const {
    return eggPrice;
}

void Aquarium::setGameTime(int _gameTime) {
    gameTime = _gameTime;
}
void Aquarium::setMoney(int _money) {
    money = _money;
}
void Aquarium::setEgg(int _egg) {
    egg = _egg;
}
void Aquarium::setEggPrice(int _eggPrice) {
    eggPrice = _eggPrice;
}

void Aquarium::add(const Guppy& guppy) {
    guppies.add(guppy);
}
void Aquarium::add(const Piranha& piranha) {
    piranhas.add(piranha);
}
void Aquarium::add(const Snail& snail) {
    snails.add(snail);
}
void Aquarium::add(const Food& food) {
    foods.add(food);
}
void Aquarium::add(const Coin& coin) {
    coins.add(coin);
}

void Aquarium::remove(const Guppy& guppy) {
    guppies.remove(guppy);
}
void Aquarium::remove(const Piranha& piranha) {
    piranhas.remove(piranha);
}
void Aquarium::remove(const Snail& snail) {
    snails.remove(snail);
}
void Aquarium::remove(const Food& food) {
    foods.remove(food);
}
void Aquarium::remove(const Coin& coin) {
    coins.remove(coin);
}

void Aquarium::tick() {
    setGameTime(getGameTime() + 1);

    for (ElementList<Guppy>* o = getGuppies().getFirst(),* next = 0; o != 0; o = next) {
        next = o->next;
        o->data.tick();
    }
    for (ElementList<Piranha>* o = getPiranhas().getFirst(),* next = 0; o != 0; o = next) {
        next = o->next;
        o->data.tick();
    }
    for (ElementList<Snail>* o = getSnails().getFirst(),* next = 0; o != 0; o = next) {
        next = o->next;
        o->data.tick();
    }
    for (ElementList<Food>* o = getFoods().getFirst(),* next = 0; o != 0; o = next) {
        next = o->next;
        o->data.tick();
    }
    for (ElementList<Coin>* o = getCoins().getFirst(),* next = 0; o != 0; o = next) {
        next = o->next;
        o->data.tick();
    }
}