
import sys
import pygame
import random
import pdb
from classes import hero
from classes import enemy
from classes import bullet
from classes import laser

class controller:

    def __init__(self):
        pygame.init()
        self.width = 750
        self.height = 750
        self.screen = pygame.display.set_mode((self.width, self.height))
        self.background = pygame.image.load('assets/bg.BMP')
        self.bullets = pygame.sprite.Group()
        self.lasers = pygame.sprite.Group()
        pygame.font.init()
        #mylassrr = laser.Laser((0,0))
        self.enemies = pygame.sprite.Group()
        enemy_ships = 15
        row = 0
        column = 0
        for i in range(enemy_ships):
            x = 300 + row
            y = 50 + column
            column += 100
            if column >= 450:
                column = 0
                row += 155
            elif row >= 650:
                break
            self.enemies.add(enemy.Enemy(x,y))

        self.hero = hero.Hero(50, 287)

        self.state = "ON"

    def mainLoop(self):
        pygame.display.set_caption("Space Invaders")
        while True:
            if(self.state == "ON"):
                self.gameLoop()
            elif(self.state == "OFF"):
                self.gameOver()

    def gameLoop(self):
        pygame.key.set_repeat(1,50)
        while self.state == "ON":


            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()

                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_UP:
                        self.hero.movement("UP")
                    elif event.key == pygame.K_DOWN:
                        self.hero.movement("DOWN")
                    if event.key == pygame.K_SPACE:
                        #self.hero.fire(self.screen)
                        #pdb.set_trace()
                        self.bullets.add(bullet.Bullet(self.hero.rect.midright))

            for e in self.bullets:
                hits = pygame.sprite.spritecollide(e, self.enemies, True)
                if (hits):
                    for i in hits:
                        i.kill()
                    e.kill()


            #for e in self.lasers:
            #    hits = pygame.sprite.spritecollide(e, self.hero, True)
            #    if (hits):
            #        print("hit")
                    #for i in hits:
                    #    i.kill()
                    #e.kill()

            for enemy in self.enemies:
                #pdb.set_trace()
                chance = random.randrange(0, 1000)
                if chance <= 4:
                    c = enemy.rect.midleft
                    l = laser.Laser(c)
                    self.lasers.add(l)


            self.enemies.update()
            self.bullets.update()
            self.lasers.update()


            self.screen.blit(self.background, (0,0))
            self.screen.blit(self.hero.image, self.hero.rect)
            self.lasers.draw(self.screen)
            self.bullets.draw(self.screen)
            self.enemies.draw(self.screen)
            pygame.display.update()


    def gameOver(self):
        self.hero.kill()
        myfont = pygame.font.SysFont(None, 30)
        message = myfont.render('Game Over', False, (0,0,0))
        self.screen.blit(message, (self.width/2,self.height/2))
        pygame.display.flip()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
