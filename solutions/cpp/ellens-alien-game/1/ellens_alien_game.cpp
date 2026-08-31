namespace targets {
// TODO: Insert the code for the alien class here

class Alien{
    public:
    Alien(int x, int y)
    {
       x_coordinate = x;
       y_coordinate = y;
       health = 3;
    }
    int get_health()
    {
        return health;
    }
    int x_coordinate;
    int y_coordinate;
    bool hit()
    {
        if(health >0)
        {
            health--;
            return true;
        }
        return false;
    }
    bool is_alive(){return health;}
    bool teleport(int x_new,int y_new)
    {
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    }
    bool collision_detection(Alien alien_new)
    {
        if(x_coordinate == alien_new.x_coordinate && y_coordinate == alien_new.y_coordinate)
            return true;
        return false;
    }
    private:
    int health;
};
}  // namespace targets
