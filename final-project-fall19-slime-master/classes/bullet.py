import pygame
#from classes import enemy
from classes import hero
import pdb

class Bullet(pygame.sprite.Sprite):

    def __init__(self, coor=(0,0)):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load("assets/Hero_Bullet.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.x = coor[0]
        self.rect.y = coor[1]
        self.x = 100
        self.y = 0
        self.speed = 50
        self.state = "LOADED"

    def update(self):
        #pdb.set_trace()
        #if self.state == "FIRED":
        #    self.shoot(self.x, self.y)
        if self.rect.x <= 800:
            self.rect.x += self.speed
        else:
            self.kill()



    def hit(self, target):
        if target == self.enemies:
            return True
        else:
            return False

    def shoot(self, screen, x, y):
        #pdb.set_trace()
        self.state = "FIRED"
        barrel = y + 5
        self.y = barrel
        screen.blit(self.image, (x, self.y))
        #self.update()
