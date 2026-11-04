abstract class Character
{
    private readonly string CharacterTypeName;

    protected Character(string characterType) => CharacterTypeName = characterType;

    public abstract int DamagePoints(Character target);

    public virtual bool Vulnerable() => false;

    public override string ToString() => $"Character is a {CharacterTypeName}";
}

class Warrior : Character
{
    public Warrior() : base("Warrior") {}

    public override int DamagePoints(Character target) => target.Vulnerable() ? 10 : 6;
}

class Wizard : Character
{
    private bool spellPrepared = false;

    public Wizard() : base("Wizard") {}

    public override int DamagePoints(Character target) => spellPrepared ? 12 : 3;

    public override bool Vulnerable() => !spellPrepared;

    public void PrepareSpell() => spellPrepared = true;
}