#include "FightScene.h"
#include <iostream>

#pragma warning(disable : 4996)

// STATYSTYKI

FightScene::Statistic::Statistic()
    : amount(100)
{
    if (!texture.loadFromFile("graphics/statistics.png"))
        throw std::runtime_error("Failed to load stat icon textures!");

    if (!font.loadFromFile("fonts/VT323-Regular.ttf"))
        throw std::runtime_error("Failed to load font!");
}
inline void FightScene::Statistic::Update()
{
    if (amount < 0)
        amount = 0;

    amountText.setString(std::to_string(amount));

    if (amount == 0)
        amountText.setColor({ 50,50,50 });
    else if (amount <= 10)
        amountText.setColor({ 200,0,0 });
    else if (amount <= 30)
        amountText.setColor({ 150,150,0 });
    else
        amountText.setColor({ 255,255,255 });
}

// INTERFEJS

constexpr int icon_col = 70;
constexpr float icon_scale = 3.f;
constexpr int text_col = 164;
constexpr int text_size = 40;
constexpr int text_off_y = 16;
constexpr int value_col = 300;
constexpr int value_off_y = 10;
constexpr int value_size = 50;
constexpr int health_row = 150;
constexpr int energy_row = 250;
constexpr int sanity_row = 350;
FightScene::UI::UI()
{
    // zdrowie
    health.amount = GameManager::player.seeStats(0);

    health.sprite.setTexture(health.texture);
    health.sprite.setTextureRect({ 0, 0, 32, 32 });
    health.sprite.setPosition(icon_col, health_row);
    health.sprite.setScale(icon_scale, icon_scale);
    
    health.name.setFont(health.font);
    health.name.setCharacterSize(text_size);
    health.name.setPosition(text_col, health_row + text_off_y);
    health.name.setString("HEALTH:");

    health.amountText.setFont(health.font);
    health.amountText.setCharacterSize(value_size);
    health.amountText.setPosition(value_col, health_row + value_off_y);

    // energia
    energy.amount = GameManager::player.seeStats(1);

    energy.sprite.setTexture(energy.texture);
    energy.sprite.setTextureRect({ 64, 0, 32, 32 });
    energy.sprite.setPosition(icon_col, energy_row);
    energy.sprite.setScale(icon_scale, icon_scale);

    energy.name.setFont(health.font);
    energy.name.setCharacterSize(text_size);
    energy.name.setPosition(text_col, energy_row + text_off_y);
    energy.name.setString("ENERGY:");

    energy.amountText.setFont(health.font);
    energy.amountText.setCharacterSize(value_size);
    energy.amountText.setPosition(value_col, energy_row + value_off_y);

    // psychika
    sanity.amount = GameManager::player.seeStats(2);

    sanity.sprite.setTexture(sanity.texture);
    sanity.sprite.setTextureRect({ 32, 0, 32, 32 });
    sanity.sprite.setPosition(icon_col, sanity_row);
    sanity.sprite.setScale(icon_scale, icon_scale);

    sanity.name.setFont(health.font);
    sanity.name.setCharacterSize(text_size);
    sanity.name.setPosition(text_col, sanity_row + text_off_y);
    sanity.name.setString("SANITY:");

    sanity.amountText.setFont(health.font);
    sanity.amountText.setCharacterSize(value_size);
    sanity.amountText.setPosition(value_col, sanity_row + value_off_y);
}

// PRZECIWNIK

constexpr int bar_col = 1100;
constexpr int bar_row = 160;
constexpr float bar_wid = 50.f;
constexpr float bar_len = 300.f;
constexpr float bar_out = 5.f;
constexpr float pt_txt_off_x = 100.f;
constexpr float pt_txt_off_y = -20.f;
constexpr int pt_txt_size = 60;
constexpr float at_txt_off_x = 100.f;
constexpr float at_txt_off_y = 60.f;
constexpr int at_txt_size = 55;
constexpr float nat_txt_off_x = 100.f;
constexpr float nat_txt_off_y = 120.f;
constexpr int nat_txt_size = 50;
FightScene::EnemyUI::EnemyUI()
    : points(0), required(100), nextAttack(NONE)
{
    if (!font.loadFromFile("fonts/VT323-Regular.ttf"))
        throw std::runtime_error("Failed to load font!");

    // pusty pasek
    pointBar_empty.setPosition(bar_col, bar_row);
    pointBar_empty.setSize({ bar_wid,bar_len });
    pointBar_empty.setOutlineThickness(bar_out);
    pointBar_empty.setFillColor({ 200,100,0 });
    pointBar_empty.setOutlineColor({ 100,50,0 });

    // wype�niaj�cy pasek
    pointBar.setPosition(bar_col, bar_row + bar_len);
    pointBar.setSize({ bar_wid,0 });
    pointBar.setOutlineThickness(bar_out);
    pointBar.setFillColor({ 0,200,0 });
    pointBar.setOutlineColor({ 0,100,0 });

    // napisy
    pointText.setFont(font);
    pointText.setPosition(bar_col + pt_txt_off_x, bar_row + pt_txt_off_y);
    pointText.setCharacterSize(pt_txt_size);

    attackText.setFont(font);
    attackText.setPosition(bar_col + at_txt_off_x, bar_row + at_txt_off_y);
    attackText.setCharacterSize(at_txt_size);
    attackText.setString("NEXT ATTACK:");

    nextAttackText.setFont(font);
    nextAttackText.setPosition(bar_col + nat_txt_off_x, bar_row + nat_txt_off_y);
    nextAttackText.setCharacterSize(nat_txt_size);
}
inline void FightScene::EnemyUI::Update()
{
    if (points > required)
        points = required;

    // pasek
    float percentage = static_cast<float>(points) / static_cast<float>(required);
    pointBar.setSize({ bar_wid, bar_len * -percentage });

    if (points == 0)
        pointBar.setOutlineThickness(0);
    else
        pointBar.setOutlineThickness(bar_out);

    // tekst z punktami
    pointText.setString(std::to_string(points) + " / " + std::to_string(required));

    // tekst z nast�pnym atakiem
    switch (nextAttack)
    {
    case NONE:
        nextAttackText.setString("-");
        break;

    case HEALTH1:
        nextAttackText.setString("Niewygodna lawka.");
        break;

    case HEALTH2:
        nextAttackText.setString("Uwaga! Niski prog.");
        break;

    case ENERGY1:
        nextAttackText.setString("Zadanie domowe.");
        break;

    case ENERGY2:
        nextAttackText.setString("Zepsuta winda.");
        break;

    case SANITY1:
        nextAttackText.setString("\"To bedzie na egzaminie.\"");
        break;

    case SANITY2:
        nextAttackText.setString("Niezapowiedziana kartkowka.");
        break;

    case HEALTH_ENERGY:
        nextAttackText.setString("Ominiete sniadanie.");
        break;

    case HEALTH_SANITY:
        nextAttackText.setString("Zarwana nocka.");
        break;

    case ENERGY_SANITY:
        nextAttackText.setString("Sesja kodowania.");
        break;

    case ALL:
        nextAttackText.setString("KOLOKWIUM");
        break;

    default:
        throw std::runtime_error("Trying to perform a nonexistent attack!");
        break;
    }
}
inline void FightScene::EnemyUI::QueueAttack(const UI& _ui)
{
    bool health_bar = _ui.health.amount > 0, energy_bar = _ui.energy.amount > 0, sanity_bar = _ui.sanity.amount > 0;
    int number = rand() % 101;

    if (!health_bar && !energy_bar)
    {
        number = rand() % 57 + 44;
        if (number > 65 && number < 77)
            number = 99;
    }
    else if (!health_bar && !sanity_bar)
    {
        number = rand() % 57 + 44;
        if (number > 43 && number < 66)
            number -= 22;
        if (number > 76 && number < 88)
            number = 99;
    }
    else if (!energy_bar && !sanity_bar)
    {
        number = (rand() % 57 + 66) % 101;
        if (number > 43 && number < 66)
            number -= 22;
        if (number > 76 && number < 88)
            number = 99;
    }
    else if (!health_bar)
        number = rand() % 79 + 22;
    else if (!energy_bar)
        number = (rand() % 79 + 44) % 101;
    else if (!sanity_bar)
        number = (rand() % 79 + 66) % 101;

    if (number < 17)
        nextAttack = HEALTH1;
    else if (number < 22)
        nextAttack = HEALTH2;
    else if (number < 39)
        nextAttack = ENERGY1;
    else if (number < 44)
        nextAttack = ENERGY2;
    else if (number < 61)
        nextAttack = SANITY1;
    else if (number < 66)
        nextAttack = SANITY2;
    else if (number < 77)
        nextAttack = HEALTH_ENERGY;
    else if (number < 88)
        nextAttack = HEALTH_SANITY;
    else if (number < 99)
        nextAttack = ENERGY_SANITY;
    else if (number < 100)
        nextAttack = NONE;
    else
        nextAttack = ALL;
}
void FightScene::EnemyUI::HandleHit()
{
    switch (nextAttack)
    {
    case NONE:
        break;

    case HEALTH1:
        GameManager::player.modifyStats(0, -(rand() % 11 + 10));
        break;

    case HEALTH2:
        GameManager::player.modifyStats(0, -(rand() % 11 + 20));
        break;

    case ENERGY1:
        GameManager::player.modifyStats(1, -(rand() % 11 + 10));
        break;

    case ENERGY2:
        GameManager::player.modifyStats(1, -(rand() % 11 + 20));
        break;

    case SANITY1:
        GameManager::player.modifyStats(2, -(rand() % 11 + 10));
        break;

    case SANITY2:
        GameManager::player.modifyStats(2, -(rand() % 11 + 20));
        break;

    case HEALTH_ENERGY:
        GameManager::player.modifyStats(0, -(rand() % 16 + 10));
        GameManager::player.modifyStats(1, -(rand() % 16 + 10));
        break;

    case HEALTH_SANITY:
        GameManager::player.modifyStats(0, -(rand() % 16 + 10));
        GameManager::player.modifyStats(2, -(rand() % 16 + 10));
        break;

    case ENERGY_SANITY:
        GameManager::player.modifyStats(1, -(rand() % 16 + 10));
        GameManager::player.modifyStats(2, -(rand() % 16 + 10));
        break;

    case ALL:
        GameManager::player.modifyStats(0, -(rand() % 31 + 10));
        GameManager::player.modifyStats(1, -(rand() % 31 + 10));
        GameManager::player.modifyStats(2, -(rand() % 31 + 10));
        break;
    }
}

// PRZEDMIOTY

constexpr float bg_col = 1100.f;
constexpr float bg_row = 750.f;
constexpr float bg_size = 160.f;
constexpr float bag_off_x = -2.f;
constexpr float bag_off_y = 5.f;
constexpr float it_scale = 3.f;
constexpr float ar_scale = 2.f;
constexpr float ar_off = 50.f;
FightScene::ItemBag::ItemBag()
    : currentItem(0), itemAmount(0), empty(true)
{
    if (!bagTexture.loadFromFile("graphics/backpack.png"))
        throw std::runtime_error("Backpack texture not found!");
    if (!itemTexture.loadFromFile("graphics/items_locations_sprite_sheet.png"))
        throw std::runtime_error("Item textures not found!");
    if (!arrowTexture.loadFromFile("graphics/arrow.png"))
        throw std::runtime_error("Arrow texture not found!");

    // dane
    // for (int i = 0; i < items_number; i++)
    //     itemAmount += player.seeItems(i);
    empty = (itemAmount == 0);

    // t�o
    background.setPosition(bg_col, bg_row);
    background.setSize({ bg_size,bg_size});
    background.setFillColor({ 100,100,100 });
    background.setOutlineThickness(10);
    background.setOutlineColor({ 50,50,50 });

    bagSprite.setTexture(bagTexture);
    bagSprite.setPosition(bg_col + bag_off_x, bg_row + bag_off_y);
    bagSprite.setScale(bg_size / 32.f, bg_size / 32.f);
    bagSprite.setColor({ 150,150,150 });

    // przedmiot
    itemSprite.setTexture(itemTexture);
    itemSprite.setTextureRect({ 0,32,32,32 });
    itemSprite.setPosition(bg_col + ((bg_size - 32.f * it_scale) / 2.f), bg_row + ((bg_size - 32.f * it_scale) / 2.f));
    itemSprite.setScale(it_scale, it_scale);

    // strza�ki
    leftArrow.setTexture(arrowTexture);
    leftArrow.setPosition(bg_col - ar_off, bg_row + ((bg_size - 32.f * ar_scale) / 2.f));
    leftArrow.setScale(-ar_scale, ar_scale);

    rightArrow.setTexture(arrowTexture);
    rightArrow.setPosition(bg_col + bg_size + ar_off, bg_row + ((bg_size - 32.f * ar_scale) / 2.f));
    rightArrow.setScale(ar_scale, ar_scale);
}
inline void FightScene::ItemBag::Update()
{
    // przedmiot
    itemSprite.setTextureRect({ 32 * currentItem, 32, 32, 32 });
}
void FightScene::ItemBag::HandleLeftArrow()
{
    if (!empty)
        for (int i = 0; i < items_number; i++)
        {
            currentItem--;
            if (currentItem < 0)
                currentItem += items_number;
            if (GameManager::player.seeItems(currentItem) != 0)
                break;
        }
}
void FightScene::ItemBag::HandleRightArrow()
{
    if (!empty)
        for (int i = 0; i < items_number; i++)
        {
            currentItem++;
            if (currentItem >= items_number)
                currentItem = 0;
            if (GameManager::player.seeItems(currentItem) != 0)
                break;
        }
}

// KLASA SCENY

FightScene::FightScene(std::shared_ptr<WindowHandler> handler)
    : windowHandler(handler)
{
    srand(time(NULL));

    if (!backgroundTexture.loadFromFile("graphics/background.png"))
        throw std::runtime_error("Failed to load background texture!");
    if (!enemyTexture.loadFromFile("graphics/enemy_sprite_sheet.png"))
        throw std::runtime_error("Failed to load enemy textures!");
    if (!playerTexture.loadFromFile("graphics/player_sprite_sheet.png"))
        throw std::runtime_error("Failed to load player textures!");
    if (!buttonTexture.loadFromFile("graphics/fight_buttons_sheet.png"))
        throw std::runtime_error("Failed to load button textures!");

    // t�o
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(1980, 1080);

    // gracz
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(440, 480);
    playerSprite.setScale(4.5f, 4.5f);

    playerSprite.setTextureRect({ 0, 32, 32, 32 });
    playerAnimator = new Animator(playerSprite, { 32, 32 }, 7, 1, 2);
    currentPlayerAnimation = IDLE;

    // przeciwnik
    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(1005, 480);
    enemySprite.setScale(-4.5f,4.5f);

    enemySprite.setTextureRect({ 0, 0, 32, 32 });
    enemyAnimator = new Animator(enemySprite, { 32, 32 }, 7, 0, 2);
    currentEnemyAnimation = IDLE;
    enemyStats.QueueAttack(stats);

    // przyciski
    attackButton.setTexture(buttonTexture);
    attackButton.setTextureRect({ 0,0,92,32 });
    attackButton.setPosition(300, 700);
    attackButton.setScale(3.f, 3.f);

    itemButton.setTexture(buttonTexture);
    itemButton.setTextureRect({ 92,0,92,32 });
    itemButton.setPosition(600, 700);
    itemButton.setScale(3.f, 3.f);
}
void FightScene::Update()
{
    UpdateSprites();
    UpdateStats();
    UpdateEnemy();
    UpdateItems();

    // opuszczanie sceny
    if (enemyStats.points >= enemyStats.required ||
        stats.health.amount == 0 && stats.energy.amount == 0 && stats.sanity.amount == 0)
        HandleExit();
    // aktualizacja sceny
    else if(currentPlayerAnimation == IDLE && currentEnemyAnimation == IDLE)
        HandleButtons();
}
void FightScene::Render(sf::RenderWindow& window)
{
    // t�o
    window.draw(backgroundSprite);

    // postacie
    window.draw(playerSprite);
    if(currentEnemyAnimation != NONE)
        window.draw(enemySprite);

    // przyciski
    window.draw(attackButton);
    window.draw(itemButton);

    // statystyki gracza
    window.draw(stats.health.sprite);
    window.draw(stats.health.name);
    window.draw(stats.health.amountText);

    window.draw(stats.energy.sprite);
    window.draw(stats.energy.name);
    window.draw(stats.energy.amountText);

    window.draw(stats.sanity.sprite);
    window.draw(stats.sanity.name);
    window.draw(stats.sanity.amountText);

    // statystyki przeciwnika
    window.draw(enemyStats.pointBar_empty);
    window.draw(enemyStats.pointBar);
    window.draw(enemyStats.pointText);
    window.draw(enemyStats.attackText);
    window.draw(enemyStats.nextAttackText);

    // przedmioty
    window.draw(itemBag.background);
    window.draw(itemBag.bagSprite);
    window.draw(itemBag.leftArrow);
    window.draw(itemBag.rightArrow);
    if(!itemBag.empty)
        window.draw(itemBag.itemSprite);
}
void FightScene::HandleMouseClick(int x, int y) {}

inline void FightScene::HandleAttack()
{
    std::cout << "FIGHT SCENE: attack pressed" << std::endl;

    static bool repeat = false;

    // tura gracza
    if (!repeat)
    {
        enemyStats.points += rand() % 21 + 5;
        currentPlayerAnimation = ATTACK;

        if (enemyStats.points >= 100)
            currentEnemyAnimation = DEATH;
        else
            currentEnemyAnimation = HURT;
    }

    // tura przeciwnika
    if (repeat)
    {
        if (enemyStats.points < 100)
        {
            if (enemyStats.nextAttack != NONE)
                currentEnemyAnimation = ATTACK;

            enemyStats.HandleHit();
            UpdateStats();

            if (enemyStats.nextAttack == EnemyUI::HEALTH1
                || enemyStats.nextAttack == EnemyUI::ENERGY1
                || enemyStats.nextAttack == EnemyUI::SANITY1)
                AudioManager::PlaySound(AudioManager::Sound::SOFT_HIT);
            else
                AudioManager::PlaySound(AudioManager::Sound::HARD_HIT);

            if (stats.health.amount == 0 && stats.energy.amount == 0 && stats.sanity.amount == 0)
                currentPlayerAnimation = DEATH;
            else if (enemyStats.nextAttack != NONE)
                currentPlayerAnimation = HURT;

            enemyStats.QueueAttack(stats);
        }
    }

    repeat = !repeat;
}
inline void FightScene::HandleItem()
{
    std::cout << "FIGHT SCENE: item pressed" << std::endl;
    if(GameManager::player.seeItems(itemBag.currentItem) != 0)
        currentPlayerAnimation = HEAL;

    if (GameManager::player.seeItems(itemBag.currentItem) == 0)
        itemBag.HandleRightArrow();
}
inline void FightScene::HandleButtons()
{
    // pobranie pozycji kursora
    sf::Vector2i mousePosition = sf::Mouse::getPosition();
    sf::Vector2f mouseWorldPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // pod�wietlanie przycisk�w
    if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
        attackButton.setColor({ 150,150,150 });
    else
        attackButton.setColor({ 255,255,255 });

    if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
        itemButton.setColor({ 150,150,150 });
    else
        itemButton.setColor({ 255,255,255 });

    if (itemBag.leftArrow.getGlobalBounds().contains(mouseWorldPosition))
        itemBag.leftArrow.setColor({ 150,150,150 });
    else
        itemBag.leftArrow.setColor({ 255,255,255 });

    if (itemBag.rightArrow.getGlobalBounds().contains(mouseWorldPosition))
        itemBag.rightArrow.setColor({ 150,150,150 });
    else
        itemBag.rightArrow.setColor({ 255,255,255 });

    // obs�uga funkcjonalno�ci przycisk�w
    static bool held = false; // czy przycisk myszy jest przytrzymywany?
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !held)
    {
        if (attackButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            HandleAttack();
        }
        else if (itemButton.getGlobalBounds().contains(mouseWorldPosition))
        {
            HandleItem();
        }
        else if (itemBag.leftArrow.getGlobalBounds().contains(mouseWorldPosition))
        {
            itemBag.HandleLeftArrow();
        }
        else if (itemBag.rightArrow.getGlobalBounds().contains(mouseWorldPosition))
        {
            itemBag.HandleRightArrow();
        }

        held = true;
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        held = false;
}
inline void FightScene::HandleExit()
{
    static int countdown = 0;

    if(countdown++ > (enemyStats.points >= enemyStats.required ? 2000 : 5000))
    {
        std::cout << "FIGHT SCENE: returning to game scene" << std::endl;
        countdown = 0;
        this->windowHandler->SetScene(std::make_shared<GameScene>(windowHandler));
    }
}

constexpr int pf_attack = 6;    // ilo�� klatek ataku gracza
constexpr int pf_death = 10;    // ilo�� klatek �mierci gracza
constexpr int pf_heal = 8;      // ilo�� klatek uzdrowienia gracza
constexpr int pf_hurt = 6;      // ilo�� klatek obra�e� gracza
constexpr int pf_idle = 7;      // ilo�� klatek bezczynno�ci gracza
constexpr int ef_attack = 6;    // ilo�� klatek ataku przeciwnika
constexpr int ef_death = 11;    // ilo�� klatek �mierci przeciwnika
constexpr int ef_heal = 8;      // ilo�� klatek uzdrowienia przeciwnika
constexpr int ef_hurt = 8;      // ilo�� klatek obra�e� przeciwnika
constexpr int ef_idle = 7;      // ilo�� klatek bezczynno�ci przeciwnika
inline void FightScene::UpdateSprites()
{
    static bool playing_player = false;
    static bool player_back = false;
    static bool playing_enemy = false;
    static bool enemy_back = false;
    
    // obs�uga animacji gracza
    switch (currentPlayerAnimation)
    {
    case NONE:break;
    case IDLE:      // ANIMACJA BEZCZYNNO�CI
    {
        playerAnimator->Update(0.016f);
    }
        break;

    case ATTACK:    // ANIMACJA ATAKU
    {
        if (!playing_player)
        {
            playerAnimator->SetAnimation(3, pf_attack);
            playing_player = true;
        }
        else
        {
            player_back = (playerAnimator->Update(0.016f) == pf_attack - 1);

            if (playing_player && player_back)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                playing_player = false;
                player_back = false;
            }
        }
    }
        break;
    
    case DEATH:     // ANIMACJA �MIERCI
    {
        if (!playing_player)
        {
            playerAnimator->SetAnimation(6, pf_death);
            playing_player = true;
            AudioManager::PlaySound(AudioManager::Sound::PLAYER_DEATH);
        }
        else
        {
            player_back = (playerAnimator->Update(0.016f) == pf_death - 1);

            if (playing_player && player_back)
            {
                currentPlayerAnimation = NONE;
                playing_player = false;
                player_back = false;
            }
        }
    }
        break;
    
    case HEAL:      // ANIMACJA UZDROWIENIA
    {
        if (!playing_player)
        {
            playerAnimator->SetAnimation(4, pf_heal);
            playing_player = true;
            AudioManager::PlaySound(AudioManager::Sound::HEAL);
        }
        else
        {
            player_back = (playerAnimator->Update(0.016f) == pf_heal - 1);

            if (playing_player && player_back)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                playing_player = false;
                player_back = false;
            }
        }
    }
        break;
    
    case HURT:      // ANIMACJA OBRA�E�
    {
        if (!playing_player)
        {
            playerAnimator->SetAnimation(5, pf_hurt);
            playing_player = true;
        }
        else
        {
            player_back = (playerAnimator->Update(0.016f) == pf_hurt - 1);

            if (playing_player && player_back)
            {
                playerAnimator->SetAnimation(1, pf_idle);
                currentPlayerAnimation = IDLE;
                playing_player = false;
                player_back = false;
            }
        }
    }
        break;
    
    default:
    {
        throw std::runtime_error("Trying to play invalid player animation!");
    }
        break;
    }

    // obs�uga animacji przeciwnika
    switch (currentEnemyAnimation)
    {
    case NONE:break;
    case IDLE:      // ANIMACJA BEZCZYNNO�CI
    {
        enemyAnimator->Update(0.016f);
    }
        break;

    case ATTACK:    // ANIMACJA ATAKU
    {
        if (!playing_enemy)
        {
            enemyAnimator->SetAnimation(1, ef_attack);
            playing_enemy = true;
        }
        else
        {
            enemy_back = (enemyAnimator->Update(0.016f) == ef_attack - 1);

            if (playing_enemy && enemy_back)
            {
                enemyAnimator->SetAnimation(0, ef_idle);
                currentEnemyAnimation = IDLE;
                playing_enemy = false;
                enemy_back = false;
            }
        }
    }
        break;

    case DEATH:     // ANIMACJA �MIERCI
    {
        if (!playing_enemy)
        {
            enemyAnimator->SetAnimation(4, ef_death);
            playing_enemy = true;
            AudioManager::PlaySound(AudioManager::Sound::ENEMY_DYING);
        }
        else
        {
            enemy_back = (enemyAnimator->Update(0.016f) == ef_death - 1);

            if (playing_enemy && enemy_back)
            {
                currentEnemyAnimation = NONE;
                playing_enemy = false;
                enemy_back = false;

                HandleAttack();
            }
        }
    }
        break;

    case HEAL:     // ANIMACJA UZDROWIENIA
    {
        if (!playing_enemy)
        {
            enemyAnimator->SetAnimation(2, ef_heal);
            playing_enemy = true;
            AudioManager::PlaySound(AudioManager::Sound::HEAL);
        }
        else
        {
            enemy_back = (enemyAnimator->Update(0.016f) == ef_heal - 1);

            if (playing_enemy && enemy_back)
            {
                enemyAnimator->SetAnimation(0, ef_idle);
                currentEnemyAnimation = IDLE;
                playing_enemy = false;
                enemy_back = false;
            }
        }
    }
    break;

    case HURT:     // ANIMACJA OBRA�E�
    {
        if (!playing_enemy)
        {
            enemyAnimator->SetAnimation(3, ef_hurt);
            playing_enemy = true;
            AudioManager::PlaySound(AudioManager::Sound::SOFT_HIT);
        }
        else
        {
            enemy_back = (enemyAnimator->Update(0.016f) == ef_hurt - 1);

            if (playing_enemy && enemy_back)
            {
                enemyAnimator->SetAnimation(0, ef_idle);
                currentEnemyAnimation = IDLE;
                playing_enemy = false;
                enemy_back = false;

                HandleAttack();
            }
        }
    }
    break;

    default:
    {
        throw std::runtime_error("Trying to play invalid enemy animation!");
    }
        break;
    }
}
inline void FightScene::UpdateStats()
{
    stats.health.amount = GameManager::player.seeStats(0);
    stats.health.Update();
    stats.energy.amount = GameManager::player.seeStats(1);
    stats.energy.Update();
    stats.sanity.amount = GameManager::player.seeStats(2);
    stats.sanity.Update();
}
inline void FightScene::UpdateEnemy()
{
    enemyStats.Update();
}
inline void FightScene::UpdateItems()
{
    itemBag.Update();
}