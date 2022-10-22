import pygame
import random
#from classes import laser

class Enemy(pygame.sprite.Sprite):

    def __init__(self, x, y):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load("assets/Alien_Ship.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y
        self.speed = 10
        #self.laser = laser.Laser()
        self.state = "DOWN"


    def update(self):
        if self.state == "DOWN":
            self.rect.y += self.speed
        if self.state == "UP":
            self.rect.y -= self.speed
        if self.rect.y >= 650:
            self.state = "UP"
        elif self.rect.y <= 0:
            self.state = "DOWN"
