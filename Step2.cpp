#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>

using namespace std;
using namespace sf;

//Init game const
    const double SCREEN_WIDTH=1020;
    const double SCREEN_HEIGH=600;
    const double RacerX=50;
    const double RacerY=450;
  /*  const double Obs1X=00;
    const double Obs1Y=490;
    const double Obs2X=300;
    const double Obs2Y=490;
    const double Obs3X=500;
    const double Obs3Y=490;
    const double Obs4X=700;
    const double Obs4Y=490;
    const double Obs5X=900;
    const double Obs5Y=490;
    const double Obs6X=1100;
    const double Obs6Y=490;*/
    const double Candy1X=100;
    const double Candy1Y=160;
    const double Candy2X=200;
    const double Candy2Y=190;
    const double Candy3X=500;
    const double Candy3Y=350;
    const double Candy4X=700;
    const double Candy4Y=150;
    const double Candy5X=900;
    const double Candy5Y=300;
RenderWindow app(VideoMode(SCREEN_WIDTH, SCREEN_HEIGH), "Mission moon");

//Creat random Number for game loop
int getRandomNumber(int a, int b);

// Create gameover screen
int gameOver();

int main()
{   int y=450;int ground;float Yvelocity=-20;bool jumping=false;
    int counterWalking=0;
   app.setFramerateLimit(30);

    Texture background,racer,cactus,candy1,candy2,candy3,candy4,candy5;//,obs1,obs2,obs3,obs4,obs5,obs6,candy1,candy2,candy3,candy4,candy5,cactus;
    //Init font
    Font myfont;
    myfont.loadFromFile("xirod.ttf");

    //Load all images
    if (!background.loadFromFile("background.png")) return EXIT_FAILURE;
      if (!racer.loadFromFile("santa.png")) return EXIT_FAILURE;
       if (!cactus.loadFromFile("cactus.png")) return EXIT_FAILURE;
     /* if (!obs1.loadFromFile("1.png")) return EXIT_FAILURE;
      if (!obs2.loadFromFile("2.png")) return EXIT_FAILURE;
      if (!obs3.loadFromFile("3.png")) return EXIT_FAILURE;
      if (!obs4.loadFromFile("4.png")) return EXIT_FAILURE;
      if (!obs5.loadFromFile("5.png")) return EXIT_FAILURE;
       if (!obs6.loadFromFile("1.png")) return EXIT_FAILURE;
       if (!candy1.loadFromFile("6.png")) return EXIT_FAILURE;*/
if (!candy2.loadFromFile("6.png")) return EXIT_FAILURE;
if (!candy3.loadFromFile("6.png")) return EXIT_FAILURE;
if (!candy4.loadFromFile("6.png")) return EXIT_FAILURE;
if (!candy5.loadFromFile("6.png")) return EXIT_FAILURE;









    Sprite Background(background),Background1(background),Racer(racer),Cactus(cactus),Cactus1(cactus),Candy1(candy1),Candy2(candy2),Candy3(candy3),Candy4(candy4),Candy5(candy5);//Candy1(candy1),Candy2(candy2),Obs1(obs1),Obs2(obs2),Obs3(obs3),Obs4(obs4),Obs5(obs5),Obs6(obs6),Candy1(candy1),Candy2(candy2),Candy3(candy3),Candy4(candy4),Candy5(candy5);
     Racer.setPosition(RacerX,RacerY);
          Racer.setTextureRect(sf::IntRect(0,0,200,197));
    /* Obs1.setPosition(Obs1X,Obs1Y);
      Obs2.setPosition(Obs2X,Obs2Y);
      Obs3.setPosition(Obs3X,Obs3Y);
      Obs4.setPosition(Obs4X,Obs4Y);
      Obs5.setPosition(Obs5X,Obs5Y);
      Obs6.setPosition(Obs6X,Obs6Y);*/
      Candy1.setPosition(Candy1X,Candy1Y);
    Candy2.setPosition(Candy2X,Candy2Y);
Candy3.setPosition(Candy3X,Candy3Y);
Candy4.setPosition(Candy4X,Candy4Y);
Candy5.setPosition(Candy5X,Candy5Y);



    double RacerX, RacerY,Obs1X, Obs1Y,Obs2X, Obs2Y,Obs3X, Obs3Y,Obs4X, Obs4Y,Obs5X,Obs5Y,Obs6X,Obs6Y,Candy1X,Candy1Y;
    Background1.setPosition(1020,0);
    Cactus.setPosition(300,450);
    Cactus1.setPosition(1500,450);

    double BackgroundX1=0;
    double BackgroundX2=-1020;
    double CactusX1=0;
    double CactusX2=-1020;
    RacerX=50;
    RacerY=450;
    Obs1X=200;
    Obs1Y=600;


    while (app.isOpen())
    {

     Cactus.move(-5,0);
  Cactus1.move(-5,0);
  if(Cactus.getPosition().x<-1020) Cactus.setPosition(300,450);
        if(Cactus1.getPosition().x<-1020) Cactus1.setPosition(1500,450);


        //Creat scrolling background
        Background.move(-10,0);
        Background1.move(-10,0);
        if(Background.getPosition().x<-1020) Background.setPosition(1020,0);
        if(Background1.getPosition().x<-1020) Background1.setPosition(1020,0);

        //Create event to handle input from keyboard
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
        }
          /*  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Background.move(-1,0) ;
       Background1.move(-1,0);
      // Racer.setTextureRect(sf::IntRect(counterWalking*200,0,200,197));
    }*/
   /*  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Obs1.move(-1,0) ;

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Obs2.move(-1,0) ;

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Obs3.move(-1,0) ;

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Obs4.move(-1,0) ;

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Obs5.move(-1,0) ;

    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Obs6.move(-1,0) ;

    }*/

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       Racer.move(4,0) ;
       Racer.setTextureRect(sf::IntRect(counterWalking*200,0,200,197));
    }
    counterWalking++;
    if(counterWalking==8){
       counterWalking=0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
       Racer.move(-4,0) ;
       Racer.setTextureRect(sf::IntRect(counterWalking*200,0,200,197));
    }
    counterWalking++;
    if(counterWalking==8){
       counterWalking=0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
       Racer.move(0,-4) ;
       Racer.setTextureRect(sf::IntRect(counterWalking*200,0,200,197));
    }
    counterWalking++;
    if(counterWalking==8){
       counterWalking=0;
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
       Racer.move(0,4) ;
       Racer.setTextureRect(sf::IntRect(counterWalking*200,0,200,197));
    }
    counterWalking++;
    if(counterWalking==8){
       counterWalking=0;
    }
         // if(Racer.getLocalBounds().intersects(Cactus1.getLocalBounds())){printf("GAME OVER");}
        //Clear and redraw position
        app.clear();
        app.draw(Background);
        app.draw(Background1);
        app.draw(Racer);
        app.draw(Cactus);
        app.draw(Cactus1);
       /* app.draw(Obs1);
        app.draw(Obs2);
        app.draw(Obs3);
        app.draw(Obs4);
        app.draw(Obs5);
        app.draw(Obs6);*/
        app.draw(Candy1);
        app.draw(Candy2);
        app.draw(Candy3);
        app.draw(Candy4);
        app.draw(Candy5);
        app.display();
    }
    return EXIT_SUCCESS;
}

