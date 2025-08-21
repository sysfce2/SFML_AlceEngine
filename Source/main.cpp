#include "Project/Scenes/Scenes.hpp"

using namespace alce;

int main()
{
    Alce.Window("Alce Engine Test", DisplayMode::Default);
    Alce.stanby = true;

    Debug.SetWaitTime(0);

    Alce.AddScene<Test1Scene::Test1>();
    Alce.AddScene<SampleScene::Sample>();
    
    Alce.SetCurrentScene("Sample");
    
    Alce.Run();

    return 0;
}

// #include <SFML/Graphics.hpp>
// #include <SFML/OpenGL.hpp>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <string>
// #include <iostream>
// #include <algorithm>

// struct Vec3 { float x=0, y=0, z=0; };
// struct Triangle { Vec3 normal; Vec3 v1, v2, v3; };

// // Cargar STL ASCII
// bool loadSTL_ASCII(const std::string &filename, std::vector<Triangle> &triangles) {
//     std::ifstream file(filename);
//     if (!file) return false;

//     std::string line;
//     Triangle tri;
//     int vertexCount = 0;
//     while (std::getline(file, line)) {
//         std::istringstream iss(line);
//         std::string word;
//         iss >> word;
//         if (word == "facet") iss >> word >> tri.normal.x >> tri.normal.y >> tri.normal.z;
//         else if (word == "vertex") {
//             if (vertexCount == 0) iss >> tri.v1.x >> tri.v1.y >> tri.v1.z;
//             else if (vertexCount == 1) iss >> tri.v2.x >> tri.v2.y >> tri.v2.z;
//             else if (vertexCount == 2) iss >> tri.v3.x >> tri.v3.y >> tri.v3.z;
//             vertexCount++;
//         } else if (word == "endfacet") { triangles.push_back(tri); tri = Triangle(); vertexCount = 0; }
//     }
//     return !triangles.empty();
// }

// // Dibujar STL
// void drawSTL(const std::vector<Triangle> &triangles) {
//     glBegin(GL_TRIANGLES);
//     for (auto &t : triangles) {
//         glNormal3f(t.normal.x, t.normal.y, t.normal.z);
//         glVertex3f(t.v1.x, t.v1.y, t.v1.z);
//         glVertex3f(t.v2.x, t.v2.y, t.v2.z);
//         glVertex3f(t.v3.x, t.v3.y, t.v3.z);
//     }
//     glEnd();
// }

// // Cubo de prueba
// std::vector<Triangle> generateCube() {
//     std::vector<Triangle> cube; float s=10;
//     Vec3 normals[6] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
//     Vec3 faces[6][4] = {
//         {{-s,-s,s},{s,-s,s},{s,s,s},{-s,s,s}}, {{-s,-s,-s},{-s,s,-s},{s,s,-s},{s,-s,-s}},
//         {{-s,s,-s},{-s,s,s},{s,s,s},{s,s,-s}}, {{-s,-s,-s},{s,-s,-s},{s,-s,s},{-s,-s,s}},
//         {{s,-s,-s},{s,s,-s},{s,s,s},{s,-s,s}}, {{-s,-s,-s},{-s,-s,s},{-s,s,s},{-s,s,-s}}
//     };
//     for(int i=0;i<6;i++){
//         cube.push_back({normals[i],faces[i][0],faces[i][1],faces[i][2]});
//         cube.push_back({normals[i],faces[i][0],faces[i][2],faces[i][3]});
//     }
//     return cube;
// }

// int main() {
//     sf::ContextSettings settings;
//     settings.depthBits = 24;
//     settings.stencilBits = 8;
//     settings.antialiasingLevel = 4;
//     settings.majorVersion = 2; settings.minorVersion = 1;

//     sf::RenderWindow window(sf::VideoMode(800,600),"STL 2D Engine",sf::Style::Default,settings);
//     window.setVerticalSyncEnabled(true);

//     std::vector<Triangle> model;
//     if (!loadSTL_ASCII("modelo.stl",model)) model = generateCube();

//     Vec3 minV{99999,99999,99999}, maxV{-99999,-99999,-99999};
//     for(auto &t:model){
//         auto check = [&](Vec3 v){ minV.x=std::min(minV.x,v.x); minV.y=std::min(minV.y,v.y); minV.z=std::min(minV.z,v.z);
//                                   maxV.x=std::max(maxV.x,v.x); maxV.y=std::max(maxV.y,v.y); maxV.z=std::max(maxV.z,v.z); };
//         check(t.v1); check(t.v2); check(t.v3);
//     }
//     Vec3 center{ (minV.x+maxV.x)/2.f, (minV.y+maxV.y)/2.f, (minV.z+maxV.z)/2.f };
//     float maxDim = std::max({maxV.x-minV.x,maxV.y-minV.y,maxV.z-minV.z});

//     glEnable(GL_DEPTH_TEST); glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); glEnable(GL_NORMALIZE); glEnable(GL_COLOR_MATERIAL);

//     float angleX=0, angleY=0, angleZ=0, scale=1;
//     float posX=0, posY=0;

//     while(window.isOpen()){
//         sf::Event event;
//         while(window.pollEvent(event)){
//             if(event.type==sf::Event::Closed) window.close();
//         }

//         // Controles
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) posX-=0.5f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) posX+=0.5f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) posY+=0.5f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) posY-=0.5f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) angleY-=1.f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) angleY+=1.f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) angleX-=1.f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) angleX+=1.f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) angleZ-=1.f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) angleZ+=1.f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) scale+=0.01f;
//         if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) scale-=0.01f;

//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         glOrtho(-50,50,-50,50,-200,200);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         GLfloat lightPos[]={50,50,50,1}; glLightfv(GL_LIGHT0,GL_POSITION,lightPos);

//         glTranslatef(posX,posY,-50.f);
//         glRotatef(angleX,1,0,0); glRotatef(angleY,0,1,0); glRotatef(angleZ,0,0,1);
//         glScalef(scale*50.f/maxDim, scale*50.f/maxDim, scale*50.f/maxDim);
//         glTranslatef(-center.x,-center.y,-center.z);

//         glColor3f(0.7f,0.7f,0.9f);
//         drawSTL(model);

//         window.display();
//     }
// }
