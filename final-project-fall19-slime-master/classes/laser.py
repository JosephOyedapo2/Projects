import pygame

class Laser(pygame.sprite.Sprite):

    def __init__(self, coor):
        #print("first", flush=True)
        pygame.sprite.Sprite.__init__(self)
        #print("here")
        self.image = pygame.image.load("assets/Alien_Bullet.png").convert_alpha()
        self.rect = self.image.get_rect()
        self.rect.x = coor[0]
        self.rect.y = coor[1]
        self.speed = 10

    def update(self):
        if self.rect.x >= -10:
            self.rect.x -= self.speed
        else:
            self.kill()
