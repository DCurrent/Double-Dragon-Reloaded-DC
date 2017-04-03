void main()
{
    void self = getlocalvar("self");
    void vAniID = getentityproperty(self,"animationID");
    int dir = getentityproperty(self,"direction");
    int a1 = getentityproperty(self,"a");
    int attacktype1 = getlocalvar("attacktype");
    int attackid1 = getentityproperty(self,"attackid");
    int animpos1 = getentityproperty(self,"animpos");
    int damage1 = getlocalvar("damage");
    int drop1 = getlocalvar("drop");
    void other = getlocalvar("other");
    int Tdir = getentityproperty(other,"direction");
    int a2 = getentityproperty(other,"a");
    int which = getlocalvar("which");
    int attacktype2 = getlocalvar("attacktype");
    int attackid2 = getentityproperty(other,"attackid");
    int animpos2 = getentityproperty(other,"animpos");
    int damage2 = getlocalvar("damage");
    int drop2 = getlocalvar("drop");

    if ( which && getentityproperty(other,"exists") ) {
       attacktype1 = attackid1;
       attacktype2 = attackid2;
       drop1 = attackid1;
       drop2 = attackid2;
       damage1 = attackid1;
       damage2 = attackid2;
       changeentityproperty(self,"hitbyid",0);
    }

    if ( which && getentityproperty(other,"exists") && getentityproperty(self,"attacking") == 1 && getentityproperty(other,"attacking") == 1 && getentityproperty(self, "invincible") == 1 && getentityproperty(self, "vulnerable") != 1 && getentityproperty(other, "invincible") == 1 && getentityproperty(other, "vulnerable") != 1 && dir!=Tdir && a1==a2 && animpos1 <= 2 && animpos2 <= 2 ) {
       updateframe(other, 1);
       updateframe(self, 1);
       damageentity(other,self,damage1,drop1,attacktype1);
    }else if ( which && getentityproperty(other,"exists") && getentityproperty(self,"attacking") == 1 && getentityproperty(other,"attacking") == 1 && getentityproperty(self, "invincible") == 0 && getentityproperty(self, "vulnerable") != 0 && getentityproperty(other, "invincible") == 0 && getentityproperty(other, "vulnerable") != 0 && dir!=Tdir && a1==a2 && animpos1 <= 2 && animpos2 <= 2 ) {
       updateframe(other, 1);
       updateframe(self, 1);
       damageentity(self,other,damage2,drop2,attacktype2);
    }
}