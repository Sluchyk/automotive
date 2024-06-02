# Копіювання Прихованих Файлів

Ця програма призначена для копіювання прихованих файлів із вихідного каталогу та його підкаталогів до цільового каталогу з новими іменами файлів.

## Вимоги

- Компілятор, сумісний із C++17
- CMake версії 3.10 або новішої
- Система контролю версій Git (необов'язково, але рекомендовано для збереження та відстеження змін)

## Як запустити

1. **Клонуйте репозиторій**

   ```sh
   git clone https://github.com/Sluchyk/automotive.git
   cd automotive
Створіть та зіберіть проект за допомогою CMake

sh
Copy code
mkdir build
cd build
cmake ..
cmake --build .
Запустіть програму

Після успішної збірки, ви знайдете виконуваний файл у папці build. Запустіть його, введіть шляхи до вихідного та цільового каталогів, і програма розпочне копіювання прихованих файлів.

sh
Copy code
./automotive
Пояснення
Програма перевіряє всі файли у вихідному каталозі та його підкаталогах. Якщо файл має ім'я, яке починається з крапки (.), він копіюється до цільового каталогу з іменем вихідного каталогу та префіксом підкресленого імені файлу.

Наприклад, якщо вихідний каталог називається sourceDir, а прихований файл має ім'я .hiddenfile1, він буде скопійований до цільового каталогу з іменем sourceDir_hiddenfile1.
