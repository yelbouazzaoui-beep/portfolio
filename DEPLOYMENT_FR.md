# Portfolio - Guide de Déploiement Complet

## ✅ État du Projet

Le projet **portfolio-youssef** est **entièrement structuré et prêt au déploiement**.

### Ce qui est fait :

- ✅ Structure complète Astro avec TypeScript
- ✅ Tous les composants implémentés (Header, Hero, About, Skills, Education, Projects, Contact, Footer, Chatbot, Resume Export)
- ✅ Fichier de données centralisé avec toutes les informations
- ✅ Thème clair/sombre avec CSS custom properties
- ✅ Animations smooth et responsive design
- ✅ Icons Lucide mappés
- ✅ README.md avec instructions
- ✅ .gitignore configuré
- ✅ vercel.json avec alias personnalisé
- ✅ package.json avec toutes les dépendances

### À faire :

1. ✔️ npm install (exécuter localement ou laisser Vercel gérer)
2. ✔️ git init et GitHubCLI setup
3. ✔️ Créer dépôt GitHub
4. ✔️ Pousser le code
5. ✔️ Déployer sur Vercel
6. ✔️ Configurer l'alias personnalisé

---

## 🚀 Instructions de Déploiement

### Étape 1 : Installation locale (Optionnel mais recommandé)

```bash
cd C:\Users\HP\Desktop\portfolio

# Installer les dépendances
npm install

# Tester localement
npm run dev
# Ouvrir http://localhost:3000
```

Si npm install est lent, cela peut être un problème de réseau. Dans ce cas, **passez directement à Vercel** (étape 3) qui gérera l'installation automatiquement.

### Étape 2 : Initialiser Git

```bash
cd C:\Users\HP\Desktop\portfolio

# Initialiser git
git init

# Ajouter tous les fichiers
git add .

# Premier commit
git commit -m "Initial commit: Complete portfolio portfolio-youssef with Astro"
```

### Étape 3 : Vérifier/Installer GitHub CLI (gh)

```bash
# Vérifier si GitHub CLI est installé
gh --version

# Si pas installé, utiliser winget
winget install --id GitHub.cli

# S'authentifier
gh auth login
# Suivre les prompts (utiliser un navigateur pour authentification)

# Configurer git pour utiliser GitHub CLI
gh auth setup-git
```

### Étape 4 : Créer un dépôt GitHub

```bash
# Créer le dépôt sur GitHub
gh repo create portfolio-youssef --source=. --remote=origin --push

# OU créer manuellement sur https://github.com/new
# - Repository name: portfolio-youssef
# - Description: Professional portfolio for Youssef EL BOUAZZAOUI
# - Public (recommandé)
# - Cliquer "Create repository"

# Puis, si création manuelle:
git remote add origin https://github.com/yelbouazzaoui-beep/portfolio-youssef.git
git branch -M main
git push -u origin main
```

### Étape 5: Installer/Vérifier Vercel CLI

```bash
# Installer Vercel CLI globalement
npm install -g vercel

# Vérifier l'installation
vercel --version

# S'authentifier
vercel login
# Suivre les prompts (utiliser un navigateur)
```

### Étape 6 : Déployer sur Vercel

```bash
# Déployer en production (depuis le répertoire du projet)
cd C:\Users\HP\Desktop\portfolio

vercel --prod --yes

# Cela va:
# 1. Détecter le projet Astro
# 2. Installer automatiquement les dépendances npm
# 3. Build le projet
# 4. Déployer sur Vercel
# 5. Générer une URL de déploiement
```

### Étape 7 : Configurer l'alias personnalisé

```bash
# Définir l'alias personnalisé
vercel alias set portfolio-youssef-el-bouazzaoui.vercel.app

# Vérifier l'alias
vercel alias list

# Redéployer pour appliquer l'alias (optionnel)
vercel --prod --yes
```

L'URL final sera: **https://portfolio-youssef-el-bouazzaoui.vercel.app**

---

## 📋 Checklist d'Exécution

```
[] 1. npm install local (optionnel)
[] 2. git init && git add . && git commit
[] 3. GitHub CLI authentification
[] 4. Créer dépôt GitHub (avec gh ou web)
[] 5. git push vers GitHub
[] 6. Vercel CLI authentification
[] 7. vercel --prod --yes
[] 8. vercel alias set portfolio-youssef-el-bouazzaoui.vercel.app
[] 9. Vérifier l'URL unique: https://portfolio-youssef-el-bouazzaoui.vercel.app
[] 10. Activer Analytics dans Vercel Dashboard (optionnel)
```

---

## 🔧 Dépannage

### npm install est très lent

→ Passez directement à Vercel. Vercel gérera l'installation automatiquement.

### Erreur "Command not found: git"

→ Git n'est pas dans le PATH. Installer Git pour Windows:

```bash
winget install --id Git.Git
```

### Erreur "Command not found: gh"

→ GitHub CLI n'est pas installé:

```bash
winget install --id GitHub.cli
```

### Erreur "Command not found: vercel"

→ Vercel CLI n'est pas installé:

```bash
npm install -g vercel
```

### Erreur d'authentification GitHub

→ Utiliser `gh auth login --web` pour utiliser le navigateur

### Érreur d'authentification Vercel

→ Utiliser `vercel login` et suivre les instructions du navigateur

---

## 📊 Valider le Déploiement

Après le déploiement, vérifier:

1. ✅ **L'URL Vercel fonctionne**
   - Accédez à: https://portfolio-youssef-el-bouazzaoui.vercel.app
   - Vérifiez que la page se charge correctement

2. ✅ **Les sections s'affichent**
   - Hero avec gradient
   - Boutons d'action
   - Navigation sticky
   - Toutes les sections du contenu

3. ✅ **Les interactions fonctionnent**
   - Toggle thème (soleil/lune)
   - Menu hamburger (mobile)
   - Formulaire de contact
   - Téléchargement du CV (PDF/Word)
   - Chatbot AI (bouton en bas à gauche)
   - Back-to-top button

4. ✅ **Responsive**
   - Testez sur mobile (Ctrl+Shift+M)
   - Testez sur tablette
   - Testez sur desktop

5. ✅ **Performance** (optionnel)
   - Ouvrez: https://pagespeed.web.dev
   - Collez l'URL du portfolio
   - Vérifiez les scores Lighthouse

---

## 🎯 Prochaines Étapes

### Modifier le contenu

Tous les changements futurs se font dans **`src/data/portfolio.ts`**:

```typescript
// Éditer les infos personnelles
const personalInfo = { ... };

// Ajouter/modificar compétences
const technicalSkills = [ ... ];

// Ajouter/modifier projets
const projects = [ ... ];
```

Puis redéployer:

```bash
git add .
git commit -m "Update portfolio content"
git push origin main
# Vercel redéploie automatiquement
```

### Activer Vercel Analytics (optionnel)

1. Accédez à: https://vercel.com/dashboard
2. Sélectionnez le projet "portfolio-youssef"
3. Allez dans "Analytics" → "Enable"
4. Attendez quelques heures pour voir les données

### Personnaliser le domaine (optionnel)

1. Dans Vercel Dashboard → Settings → Domains
2. Ajouter un domaine personnel (ex: portfolio.example.com)
3. Suivre les instructions de configuration DNS

---

## 📞 Support

En cas de problème:

1. **Vérifier les logs Vercel**
   - Vercel Dashboard → Deployments → Voir les logs

2. **Vérifier la syntaxe TypeScript**

   ```bash
   npx tsc --noEmit
   ```

3. **Reconstruire le projet**

   ```bash
   npm run build
   npm run preview
   ```

4. **Nettoyer et réinstaller**
   ```bash
   rm -r node_modules
   npm install
   npm run build
   ```

---

## 🎉 Résumé

Votre portfolio est prêt ! Il vous suffit de:

1. Exécuter les commandes de déploiement (étapes 1-7 ci-dessus)
2. Attendre ~2-3 minutes pour le déploiement
3. Accéder à votre URL unique Vercel
4. Partager avec le monde! 🚀

**URL finale:**

```
https://portfolio-youssef-el-bouazzaoui.vercel.app
```

Bonne chance! 💪
