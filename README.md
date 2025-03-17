**📌 Description**
------------------

Ce projet vise à concevoir un **bureau intelligent** permettant d'optimiser la consommation d’énergie en fonction de la présence de l’utilisateur et des conditions ambiantes.

### **🔹 Fonctionnalités principales :**

*   🔍 **Détection de présence** : Extinction automatique des équipements en cas d'absence prolongée.
    
*   💡 **Gestion intelligente de l'éclairage** : Ajustement automatique de la luminosité en fonction de la lumière ambiante.
    
*   📊 **Suivi de consommation énergétique** : Mesure et transmission des données via **MQTT**.
    
*   🔗 **Communication inter-systèmes** : Partage des données avec d’autres dispositifs via MQTT.
    

**🛠 Matériel Utilisé**
-----------------------

*   ESP32 ou ESP8266
    
*   Capteur PIR ou capacitif (détection de présence)
    
*   Capteur de luminosité **BH1750**
    
*   Relais pour le contrôle des équipements électriques
    
*   Capteur de courant **ACS712**
    
*   Lampe LED basse consommation
    

**⚙️ Installation et Compilation**
----------------------------------

### **1️⃣ Installer PlatformIO**

Si PlatformIO n’est pas encore installé :

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   pip install platformio   `

### **2️⃣ Cloner le projet**

```
git clone https://github.com/Ouass77ck/zendesk  cd zendesk
``` 

### **3️⃣ Installer les bibliothèques nécessaires**

```
pio lib install "knolleary/PubSubClient"  pio lib install "claws/BH1750"
```

### **4️⃣ Compiler le projet**

```
pio run
```

Si tout se passe bien, la compilation doit réussir ✅

**▶️ Téléverser le Code sur l’ESP32**
-------------------------------------

```
pio run --target upload
```

**📡 Ouvrir le Moniteur Série**
-------------------------------

```
pio device monitor
```

(Utile pour vérifier les logs et debug du projet)

**💡 Remarque**
---------------

*   Assurez-vous d’avoir un **broker MQTT** actif (ex: Mosquitto).
    
*   Vérifiez le fichier **wifi\_mqtt.h** pour configurer le WiFi et l’adresse MQTT.
