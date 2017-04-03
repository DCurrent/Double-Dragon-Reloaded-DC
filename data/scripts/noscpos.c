// Removes scroll pos effect allowing entities to be spawned exactly at defined x coordinate
void main()
{
    void self = getlocalvar("self"); //Get calling entity.
    int x = getentityproperty(self,"x"); //Get character's x coordinate
    int XPos = openborvariant("xpos");

    changeentityproperty(self, "position", x - XPos);
}
