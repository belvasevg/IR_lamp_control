#include <IRremote.h>
/***
 * \brief Класс для хранения значений с пульта управления лампой.
 * \details Для работы программы необходимо использовать протокол NEC и 32 бита передаваемой
 * информации.
 * \param LIGHT_TURN №1. Значение включения и выключения лампы
 * \param RGB_TURN №2. Значение переключения на RGB-формат
 * \param BRIGHTNESS_UP №3. Значение увеличения яркости лампы
 * \param BRIGHTNESS_DOWN №4. Значение уменьшения яркости лампы
 * \param WARM_OR_RGB_CHANGE №5. Значение тёплого цвета в обычном режиме и 
 * переключение цветов в RGB режиме
 * \param COLD_OR_RGB №6. Значение холодного цвета в обычном режиме и 
 * какой-то манипуляции в RGB режиме
 * \param CHANGING №7. Значение какой-то смены на пульте
 * \param CRESCENT_MOON №8. Полумесяц на пульте. Скорее всего ночной режим
 * \param HALF_OF_WARM №9. Значение половины тёплого цвета в обычном режиме
 * \param HALF_OF_COLD №10. Значение половины холодного цвета в обычном режиме
 */
class LampControl
{
private:
    const long LIGHT_TURN = 0x5ED9768,
    RGB_TURN = 0x5EDAF50,          
    BRIGHTNESS_UP = 0x5EDD52A,     
    BRIGHTNESS_DOWN = 0x5ED3DC2,
    WARM_OR_RGB_CHANGE = 0x5EDF708,
    COLD_OR_RGB = 0x5EDD728,
    CHANGING = 0x5ED906F,
    CRESCENT_MOON = 0x5ED40BF,
    HALF_OF_WARM = 0x5ED5FA0,
    HALF_OF_COLD = 0x5ED15EA;
public:
    long get_signal(unsigned int par);
};