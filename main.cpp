#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include<sstream>
#include "Collision.hpp"

using namespace std;
using namespace sf;


unsigned int menuSelection=0;

Clock menuClock;

bool gameplay = true;

const double SCREEN_WIDTH=1020;
const double SCREEN_HEIGH=512;
int gamelevel=1;

RenderWindow app(VideoMode(SCREEN_WIDTH, SCREEN_HEIGH), "Mission moon");
Event event;



int main()
{

    int y=450;int ground;float Yvelocity=-20;bool jumping=false;
    bool music=true,mmusic=true,overM=true,music1=true,levelend=false;
    int gameState=0;
    unsigned int menuState=0;
    int counterWalking=0;
    const float gravity=1;
    int groundHeight=455;
    sf::Vector2f velocity(sf::Vector2f(0,0));
    app.setFramerateLimit(30);
    float moveSpeed=1.0f,jumpSpeed=20.0f;
    int score = 0;


    Texture background,racer,min1,candy1,candy2,candy3,candy4,candy5,candy6,obs1,obs2,obs3,obs4,obs5,obs6;

    Texture gameover,n,menu,leveldone,helppage;
    Sprite sgameover,N,Menu,Leveldone,Helppage;

    gameover.loadFromFile("resources/gameover.png");
    n.loadFromFile("resources/testing.jpg");
    menu.loadFromFile("resources/startpage.png");
    N.setTexture(n);
    Menu.setTexture(menu);
    gameover.setSmooth(true);
    sgameover.setTexture(gameover);
    Leveldone.setTexture(leveldone);
    leveldone.loadFromFile("resources/minion 1 passed.jpg");
    helppage.loadFromFile("resources/minions-bob-joy.jpg");
    Helppage.setTexture(helppage);


    Texture bg, ballon1,ballon2,ballon3,ballon4,ballon5,ballon6,bird1,bird2,bird3;

    Music start,start1;
    start.openFromFile("resources/music.wav");
    start.setVolume(20);

    SoundBuffer collect;
    collect.loadFromFile("resources/music1.wav");
    Sound Collect;
    Collect.setBuffer(collect);
    SoundBuffer over;
    over.loadFromFile("resources/over.wav");
    Sound Over;
    Over.setBuffer(over);



    //Sprite Ballon1(ballon1),Ballon2(ballon2),Ballon3(ballon3),Ballon4(ballon4),Ballon5(ballon5),Ballon6(ballon6),Ballon1p(ballon1),
      //   Ballon2p(ballon2),Ballon3p(ballon3),Ballon4p(ballon4),Ballon5p(ballon5),Ballon6p(ballon6),Bird2(bird2),Bird3(bird3),Bird1p(bird1),Bird2p(bird2),Bird3p(bird3);


                 //Images of level1
      if (!background.loadFromFile("resources/bgFinal.png")) return EXIT_FAILURE;
      if (!racer.loadFromFile("resources/minion1.png")) return EXIT_FAILURE;
      if (!obs1.loadFromFile("resources/1.png")) return EXIT_FAILURE;
      if (!obs2.loadFromFile("resources/2.png")) return EXIT_FAILURE;
      if (!obs3.loadFromFile("resources/3.png")) return EXIT_FAILURE;
      if (!candy1.loadFromFile("resources/6.png")) return EXIT_FAILURE;
      if (!candy2.loadFromFile("resources/6.png")) return EXIT_FAILURE;
      if (!candy3.loadFromFile("resources/6.png")) return EXIT_FAILURE;

      //Images of level2

      if (!bg.loadFromFile("resources/bg2.png")) return EXIT_FAILURE;
      if (!min1.loadFromFile("resources/bob.png")) return EXIT_FAILURE;
      if (!bird1.loadFromFile("resources/o3.png")) return EXIT_FAILURE;

      if (!bird2.loadFromFile("resources/o2.png")) return EXIT_FAILURE;
      if (!bird3.loadFromFile("resources/bird1.png")) return EXIT_FAILURE;
      if (!ballon1.loadFromFile("resources/b y.png")) return EXIT_FAILURE;
      if (!ballon2.loadFromFile("resources/b r.png")) return EXIT_FAILURE;
      if (!ballon3.loadFromFile("resources/b o.png")) return EXIT_FAILURE;
      if (!ballon4.loadFromFile("resources/b b.png")) return EXIT_FAILURE;
      if (!ballon4.loadFromFile("resources/b g.png")) return EXIT_FAILURE;
      if (!ballon5.loadFromFile("resources/b p.png")) return EXIT_FAILURE;

      //Images of level 3
      Texture min2, bg3,pearl1,pearl2,pearl3,pearl4,pearl5,pearl6,coral1,coral2,coral3,coral4,coral5,coral6,seagull;
       if (!bg3.loadFromFile("resources/seabg.png")) return EXIT_FAILURE;
      if (!min2.loadFromFile("resources/stuart.png")) return EXIT_FAILURE;
      if (!pearl1.loadFromFile("resources/prl3.png")) return EXIT_FAILURE;
      if (!pearl2.loadFromFile("resources/prl4.png")) return EXIT_FAILURE;
      if (!pearl3.loadFromFile("resources/prl6.png")) return EXIT_FAILURE;
      if (!coral1.loadFromFile("resources/crl1.png")) return EXIT_FAILURE;
      if (!coral2.loadFromFile("resources/crl2.png")) return EXIT_FAILURE;
      if (!coral3.loadFromFile("resources/crl6.png")) return EXIT_FAILURE;



Sprite Background(background),Background1(background),Racer(racer),Candy1(candy1),Candy2(candy2),Candy3(candy3),Obs1(obs1),
       Obs2(obs2),Obs3(obs3),Obs1p(obs1),Obs2p(obs2),Obs3p(obs3),Candy1p(candy1),Candy2p(candy2),Candy3p(candy3);
 //Sprite Candy4(ballon1), Candy5(ballon1), Candy6(ballon1), Candy4p(ballon1), Candy5p(ballon1), Candy6p(ballon1),Obs4(obs1),Obs5(obs2),Obs6(obs3),Obs4p(obs1),Obs5p(obs2),Obs6p(obs3);

    //level1

      Racer.setPosition(50,350);
      Racer.setTextureRect(sf::IntRect(0,0,200,197));
      Obs1.setPosition(300,350);
      Obs2.setPosition(750,350);
      Obs3.setPosition(1000,350);

      Candy1.setPosition(500,350);
      Candy2.setPosition(1150,350);
      Candy3.setPosition(1350,350);

    double RacerX, RacerY,Obs1X, Obs1Y,Obs2X, Obs2Y,Obs3X, Obs3Y,Obs4X, Obs4Y,Obs5X,Obs5Y,Obs6X,Obs6Y,Candy1X,Candy1Y,Candy2X,Candy2Y,Candy3X,Candy3Y,Candy4X,Candy4Y,Candy5X,Candy5Y,Candy6X,Candy6Y;
    Background1.setPosition(1020,0);
    Background1.setPosition(1020,0);

    Obs1p.setPosition(1500,350);
    Obs2p.setPosition(1950,350);
    Obs3p.setPosition(2350,350);


    Candy1p.setPosition(1700,350);
    Candy2p.setPosition(2400,350);
    Candy3p.setPosition(2550,350);

      //Level 2

      Racer.setPosition(50,350);
      Racer.setTextureRect(sf::IntRect(0,0,200,197));
      Obs1.setPosition(300,50);
      Obs2.setPosition(750,200);
      Obs3.setPosition(1000,100);

      Candy1.setPosition(500,30);
      Candy2.setPosition(900,70);
      Candy3.setPosition(1400,300);


     Background1.setPosition(1020,0);
     Obs1p.setPosition(1500,50);
     Obs2p.setPosition(1950,200);
     Obs3p.setPosition(2350,100);
     Candy1p.setPosition(1700,30);
     Candy2p.setPosition(2250,70);
     Candy3p.setPosition(2500,300);

    //level 2 end
    double BackgroundX1=0;
    double BackgroundX2=-1020;

    double BGX1=0;
    double BGX2=-1020;

  //lEVEL3

      Racer.setPosition(50,600);
      Racer.setTextureRect(sf::IntRect(0,0,200,197));
      Obs1.setPosition(300,350);
      Obs2.setPosition(700,350);
      Obs3.setPosition(1100,350);

      Candy1.setPosition(500,350);
      Candy2.setPosition(900,350);
      Candy3.setPosition(1400,350);


     Background1.setPosition(1020,0);
     Obs1p.setPosition(1500,350);
     Obs2p.setPosition(2000,350);
     Obs3p.setPosition(2300,350);
     Candy1p.setPosition(1700,350);
     Candy2p.setPosition(2250,350);
     Candy3p.setPosition(2500,350);
    /// score

    Font fscore;
    fscore.loadFromFile("resources/arial.ttf");
    ostringstream sscore;
    sscore << "SCORE: " << score;

    Text tscore;
    tscore.setCharacterSize(50);
    tscore.setPosition(750,30);
    tscore.setFont(fscore);
    tscore.setString(sscore.str());
    tscore.setFillColor(Color::Red);

    //MENU

    Font fstart;
    fstart.loadFromFile("resources/arial.ttf");

    Text tstart("START",fstart,75);
    tstart.setPosition(250, 150);
    tstart.setFillColor(Color::Yellow);

    Font fhelp;
    fhelp.loadFromFile("resources/arial.ttf");

    Text thelp("HELP",fhelp,75);
    thelp.setPosition(250, 250);
    thelp.setFillColor(Color::Yellow);

    Clock mclock;

        while(app.isOpen()){
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
            app.close();
        }

        if(gameplay == true){
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed){
                app.close();
            }

        }


        if(gameState==0){

        if(music) start.play();
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            start.pause();
            music=false;
        }
             switch(menuState){
            case 0:
                tstart.setFillColor(Color::Yellow);
                thelp.setFillColor(Color::Red);
                break;
            case 1:
                thelp.setFillColor(Color::Yellow);
                tstart.setFillColor(Color::Red);
                break;
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) && mclock.getElapsedTime().asMilliseconds()>150){
                if(menuState > 0){
                    menuState--;
                }
                else {
                    menuState = 1;
                }
                mclock.restart();
            }

            if(Keyboard::isKeyPressed(Keyboard::Down) && mclock.getElapsedTime().asMilliseconds()>150){
                if(menuState < 1){
                    menuState++;
                }
                else {
                    menuState = 0;
                }
                mclock.restart();
            }

            if(Keyboard::isKeyPressed(Keyboard::Enter)){
                switch(menuState){
                case 0:
                    gameState = 1;
                    break;
                case 1:
                    gameState = 3;
                    break;
                }
            }
            app.clear();
            app.draw(Menu);
            app.draw(tstart);
            app.draw(thelp);
            app.display();

        }


    if(gameState==1)
    {
        if(gamelevel==1){

        Obs1.move(-8,0);
        Obs2.move(-8,0);
        Obs3.move(-8,0);
        Obs1p.move(-8,0);
        Obs2p.move(-8,0);
        Obs3p.move(-8,0);


        Candy1.move(-8,0);
        Candy2.move(-8,0);
        Candy3.move(-8,0);
        Candy1p.move(-8,0);
        Candy2p.move(-8,0);
        Candy3p.move(-8,0);



         if(Obs1.getPosition().x<-1020) Obs1.setPosition(300,350);
         if(Obs2.getPosition().x<-1020) Obs2.setPosition(750,350);
         if(Obs3.getPosition().x<-1020) Obs3.setPosition(1000,350);
         if(Obs1p.getPosition().x<-1020) Obs1p.setPosition(1500,350);
         if(Obs2p.getPosition().x<-1020) Obs2p.setPosition(1950,350);
         if(Obs3p.getPosition().x<-1020) Obs3p.setPosition(2350,350);


         if(Candy1.getPosition().x<-1020) Candy1.setPosition(500,350);
         if(Candy2.getPosition().x<-1020) Candy2.setPosition(1150,350);
         if(Candy3.getPosition().x<-1020) Candy3.setPosition(1350,350);
         if(Candy1p.getPosition().x<-1020) Candy1p.setPosition(1700,350);
         if(Candy2p.getPosition().x<-1020) Candy2p.setPosition(2400,350);
         if(Candy3p.getPosition().x<-1020) Candy3p.setPosition(2550,350);




            //Creat scrolling background

           Background.move(-15,0);
           Background1.move(-15,0);
           if(Background.getPosition().x<-1020) Background.setPosition(1000,0);
           if(Background1.getPosition().x<-1020) Background1.setPosition(1000,0);

                 //Collision

           if(Collision::PixelPerfectTest(Racer,Obs1)){
                  Obs1.setPosition(-200,-200);
                 // gameplay=false;
                    }
          if(Collision::PixelPerfectTest(Racer,Obs2)){
                  Obs2.setPosition(-200,-200);
                  gameplay=false;
                  if(music) start.play(), start.setVolume(0);
                  if(overM) Over.play();
                    }
          if(Collision::PixelPerfectTest(Racer,Obs3)){
                  Obs3.setPosition(-200,-200);
                  gameplay=false;
                  if(music) start.play(), start.setVolume(0);
                  if(overM) Over.play();
                    }
         if(Collision::PixelPerfectTest(Racer,Candy1)){
                  Candy1.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                  if(mmusic) Collect.play();
                   }
         if(Collision::PixelPerfectTest(Racer,Candy2)){
                  Candy2.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                  if(mmusic) Collect.play();
                     }
         if(Collision::PixelPerfectTest(Racer,Candy3)){
                  Candy3.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                  if(mmusic) Collect.play();
                      }
                       //Jumping

           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                 velocity.x=moveSpeed;
           else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                 velocity.x=-moveSpeed;

            else velocity.x=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            velocity.y=-jumpSpeed;
            if(Racer.getPosition().y+racer.getSize().y<groundHeight ||velocity.y<0)
            {
                velocity.y+=gravity;

            }
            else{
                Racer.setPosition(Racer.getPosition().x,groundHeight-racer.getSize().y);
                velocity.y=0;
            }
            Racer.move(velocity.x,velocity.y);

        app.clear();

        app.draw(Background);
        app.draw(Background1);
        app.draw(Racer);

        app.draw(Obs1);
        app.draw(Obs2);
        app.draw(Obs3);

        app.draw(Candy1);
        app.draw(Candy2);
        app.draw(Candy3);

        app.draw(tscore);
        app.display();
        if(score == 10){

            gamelevel++;
            app.clear();

        }

        app.clear();
        }

   if(gamelevel==2){

        Obs1.move(-8,0);
        Obs2.move(-8,0);
        Obs3.move(-8,0);
        Obs1p.move(-8,0);
        Obs2p.move(-8,0);
        Obs3p.move(-8,0);
        Candy1.move(-8,0);
        Candy2.move(-8,0);
        Candy3.move(-8,0);
        Candy1p.move(-8,0);
        Candy2p.move(-8,0);
        Candy3p.move(-8,0);


         if(Obs1.getPosition().x<-1020) Obs1.setPosition(300,50);
         if(Obs2.getPosition().x<-1020) Obs2.setPosition(750,200);
         if(Obs3.getPosition().x<-1020) Obs3.setPosition(1000,100);
         if(Obs1p.getPosition().x<-1020) Obs1p.setPosition(1500,50);
         if(Obs2p.getPosition().x<-1020) Obs2p.setPosition(1950,200);
         if(Obs3p.getPosition().x<-1020) Obs3p.setPosition(2350,100);

         if(Candy1.getPosition().x<-1020) Candy1.setPosition(500,30);
         if(Candy2.getPosition().x<-1020) Candy2.setPosition(1250,70);
         if(Candy3.getPosition().x<-1020) Candy3.setPosition(1350,300);

         if(Candy1p.getPosition().x<-1020) Candy1p.setPosition(1700,30);
         if(Candy2p.getPosition().x<-1020) Candy2p.setPosition(2400,70);
         if(Candy3p.getPosition().x<-1020) Candy3p.setPosition(2550,300);

         Background.move(-15,0);
         Background1.move(-15,0);
         if(Background.getPosition().x<-1020) Background.setPosition(1000,0);
         if(Background1.getPosition().x<-1020) Background1.setPosition(1000,0);



        if(Collision::PixelPerfectTest(Racer,Obs1)){
        Obs1.setPosition(-200,-200);
        gameplay=false;
                }
        if(Collision::PixelPerfectTest(Racer,Obs2)){
        Obs2.setPosition(-200,-200);
        gameplay=false;
        if(music) start.play(), start.setVolume(0);
                  if(overM) Over.play();
                }
        if(Collision::PixelPerfectTest(Racer,Obs3)){
        Obs3.setPosition(-200,-200);
        gameplay=false;
        if(music) start.play(), start.setVolume(0);
                  if(overM) Over.play();
                }
        if(Collision::PixelPerfectTest(Racer,Candy1)){
                  Candy1.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                   if(mmusic) Collect.play();
                    }
       if(Collision::PixelPerfectTest(Racer,Candy2)){
                  Candy2.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                   if(mmusic) Collect.play();
                    }

      if(Collision::PixelPerfectTest(Racer,Candy3)){
                  Candy3.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                   if(mmusic) Collect.play();

                  }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocity.x=moveSpeed;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocity.x=-moveSpeed;

             else velocity.x=0;
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
             velocity.y=-jumpSpeed;
             if(Racer.getPosition().y+racer.getSize().y<groundHeight ||velocity.y<0)
            {
                velocity.y+=gravity;

            }
            else{
                Racer.setPosition(Racer.getPosition().x,groundHeight-racer.getSize().y);
                velocity.y=0;
            }
            Racer.move(velocity.x,velocity.y);

            Background.setTexture(bg);
            Background1.setTexture(bg);
            Obs1.setTexture(bird1);
            Obs1p.setTexture(bird1);
            Obs2.setTexture(bird2);
            Obs2p.setTexture(bird2);
            Obs3.setTexture(bird3);
            Obs3p.setTexture(bird3);
            Candy1.setTexture(ballon1);
            Candy2.setTexture(ballon2);
            Candy3.setTexture(ballon3);
            Candy1p.setTexture(ballon1);
            Candy2p.setTexture(ballon2);
            Candy3p.setTexture(ballon3);


            app.clear();

            app.draw(Background);
            app.draw(Background1);
            app.draw(Racer);

            app.draw(Obs1);
            app.draw(Obs2);
            app.draw(Obs3);

            app.draw(Candy1);
            app.draw(Candy2);
            app.draw(Candy3);

            app.draw(tscore);
            app.display();
            if(score == 20){
               gamelevel++;
               app.clear();
                 }
   }
    if(gamelevel==3){

        Obs1.move(-5,0);
        Obs2.move(-5,0);
        Obs3.move(-5,0);
        Obs1p.move(-5,0);
        Obs2p.move(-5,0);
        Obs3p.move(-5,0);
        Candy1.move(-5,0);
        Candy2.move(-5,0);
        Candy3.move(-5,0);
        Candy1p.move(-5,0);
        Candy2p.move(-5,0);
        Candy3p.move(-5,0);


         if(Obs1.getPosition().x<-1020) Obs1.setPosition(300,368);
         if(Obs2.getPosition().x<-1020) Obs2.setPosition(750,365);
         if(Obs3.getPosition().x<-1020) Obs3.setPosition(1000,356);
         if(Obs1p.getPosition().x<-1020) Obs1p.setPosition(1500,368);
         if(Obs2p.getPosition().x<-1020) Obs2p.setPosition(1950,365);
         if(Obs3p.getPosition().x<-1020) Obs3p.setPosition(2350,356);

         if(Candy1.getPosition().x<-1020) Candy1.setPosition(500,350);
         if(Candy2.getPosition().x<-1020) Candy2.setPosition(1150,350);
         if(Candy3.getPosition().x<-1020) Candy3.setPosition(1350,350);

         if(Candy1p.getPosition().x<-1020) Candy1p.setPosition(1700,350);
         if(Candy2p.getPosition().x<-1020) Candy2p.setPosition(2400,350);
         if(Candy3p.getPosition().x<-1020) Candy3p.setPosition(2550,350);

         Background.move(-10,0);
         Background1.move(-10,0);
         if(Background.getPosition().x<-1020) Background.setPosition(995,0);
         if(Background1.getPosition().x<-1020) Background1.setPosition(995,0);



        if(Collision::PixelPerfectTest(Racer,Obs1)){
        Obs1.setPosition(-200,-200);
        gameplay=false;
                }
        if(Collision::PixelPerfectTest(Racer,Obs2)){
        Obs2.setPosition(-200,-200);
        gameplay=false;
        if(music) start.play(), start.setVolume(0);
                  if(overM) Over.play();
                }
        if(Collision::PixelPerfectTest(Racer,Obs3)){
        Obs3.setPosition(-200,-200);
        gameplay=false;
        if(music) start.play(), start.setVolume(0);
                  if(overM) Over.play();
                }
        if(Collision::PixelPerfectTest(Racer,Candy1)){
                  Candy1.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                   if(mmusic) Collect.play();
                    }
       if(Collision::PixelPerfectTest(Racer,Candy2)){
                  Candy2.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                   if(mmusic) Collect.play();
                    }

      if(Collision::PixelPerfectTest(Racer,Candy3)){
                  Candy3.setPosition(-200,-200);
                  score++;
                  sscore.str("");
                  sscore << "SCORE: " << score;
                  tscore.setString(sscore.str());
                   if(mmusic) Collect.play();

                  }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocity.x=moveSpeed;
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocity.x=-moveSpeed;

             else velocity.x=0;
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
             velocity.y=-jumpSpeed;
             if(Racer.getPosition().y+racer.getSize().y<groundHeight ||velocity.y<0)
            {
                velocity.y+=gravity;

            }
            else{
                Racer.setPosition(Racer.getPosition().x,groundHeight-racer.getSize().y);
                velocity.y=0;
            }
            Racer.move(velocity.x,velocity.y);
            Background.setTexture(bg3);
            Background1.setTexture(bg3);
            Obs1.setTexture(coral1);
            Obs1p.setTexture(coral1);
            Obs2.setTexture(coral2);
            Obs2p.setTexture(coral2);
            Obs3.setTexture(coral3);
            Obs3p.setTexture(coral3);
            Candy1.setTexture(pearl1);
            Candy2.setTexture(pearl2);
            Candy3.setTexture(pearl3);
            Candy1p.setTexture(pearl1);
            Candy2p.setTexture(pearl2);
            Candy3p.setTexture(pearl3);


            app.clear();

            app.draw(Background);
            app.draw(Background1);
            app.draw(Racer);

            app.draw(Obs1);
            app.draw(Obs2);
            app.draw(Obs3);

            app.draw(Candy1);
            app.draw(Candy2);
            app.draw(Candy3);

            app.draw(tscore);
            app.display();

    if(score==30)
    gameplay=false;
                  }


        }
            if(gameState == 3){
            if(music) start.play(), start.setVolume(0);
            app.clear();
            app.draw(Helppage);
            app.display();
            if(Keyboard::isKeyPressed(Keyboard::A)){
                gameState = 0;
            }
         }

        }
        else if(gameplay == false){
        while(app.pollEvent(event)){
        if (event.type == Event::Closed){
                    app.close();
                }
            }

            app.clear();

            app.draw(sgameover);
            app.display();

                   }

        }

        return EXIT_SUCCESS;
}



