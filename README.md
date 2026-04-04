# Snake Game

This is a simple Snake game implemented in C using the Raylib graphics library.

## Features

- Snake moves with arrow keys
- Food appears randomly
- Snake grows when eating food
- Collision detection (walls and self)
- Score system
- Game over screen with restart option

## Requirements

- Raylib library installed

## Compilation

Run the following command to compile the game:

```bash
make
```

## Execution

Run the following command to play the game:

```bash
./snake_game
```

Enjoy the game!

# Portfolio - Youssef EL BOUAZZAOUI

A modern, professional portfolio built with **Astro**, **TypeScript**, and **Tailwind CSS**, deployed on **Vercel**.

🌐 **Live:** [https://portfolio-youssef-el-bouazzaoui.vercel.app](https://portfolio-youssef-el-bouazzaoui.vercel.app)

📚 **Documentation:**

- [PROJECT_SUMMARY_FR.md](PROJECT_SUMMARY_FR.md) - Résumé complet du projet créé
- [DEPLOYMENT_FR.md](DEPLOYMENT_FR.md) - Guide détaillé de déploiement Vercel

---

## 🎨 Features

### ✨ Modern Design

- **Glassmorphism UI** with backdrop blur effects
- **Dark/Light theme toggle** with automatic detection
- **Smooth animations** and scroll-reveal effects
- **Fully responsive** - optimized for mobile, tablet, and desktop

### 🎯 Dynamic Sections

All sections automatically appear/disappear based on content data:

- **Hero** - Full-screen introduction with gradient text
- **About** - Personal story and philosophy
- **Skills** - Technical and soft skills by category
- **Education** - Timeline with institution links
- **Experience** - (Optional) Stage/work history
- **Publications** - (Optional) Research papers
- **Projects** - Portfolio showcase with tags and links
- **Contact** - Functional form with email integration
- **Footer** - Navigation and social links

### 🤖 AI Chatbot

Floating chatbot assistant with:

- Quick action chips
- Client-side knowledge base
- Markdown response rendering
- Auto-navigation to sections

### 📄 Resume Export

Export CV in two formats:

- **PDF** - Optimized for online applications
- **Word (.docx)** - For ATS systems and manual editing

### 🔐 SEO & Performance

- Semantic HTML structure
- Skip links for accessibility
- Vercel Analytics integration
- Static site generation (fast loading)

---

## 🚀 Getting Started

### Prerequisites

- **Node.js** 18+
- **npm** or **yarn**
- **Git**

### Installation

1. **Clone the repository**

   ```bash
   git clone https://github.com/yelbouazzaoui-beep/portfolio.git
   cd portfolio
   ```

2. **Install dependencies**

   ```bash
   npm install
   # or
   yarn install
   ```

3. **Start development server**
   ```bash
   npm run dev
   ```
   Open [http://localhost:3000](http://localhost:3000) in your browser.

---

## 📝 Customization

### Edit Content

All portfolio content is centralized in **`src/data/portfolio.ts`**:

```typescript
// Example: Update personal info
const personalInfo: PersonalInfo = {
  firstName: "Youssef",
  lastName: "EL BOUAZZAOUI",
  title: "Computer Science Student",
  email: "you2007b@gmail.com",
  // ... more fields
};

// Add skills
const technicalSkills: Skill[] = [
  { name: "React", icon: "Code2", category: "Web Development" },
  // ... more skills
];

// Add projects
const projects: Project[] = [
  {
    title: "My Project",
    description: "...",
    technologies: ["React", "Node.js"],
  },
  // ... more projects
];
```

**That's it!** All sections will automatically update based on your data.

### Modify Styles

- **Global styles**: `src/layouts/BaseLayout.astro` (CSS custom properties)
- **Component styles**: Each component has `<style>` blocks
- **Tailwind classes**: Used throughout for responsive design
- **Theme colors**: Defined via CSS variables (dark & light modes)

### Customize Components

Each component is modular and reusable:

- `src/components/Header.astro` - Navigation bar
- `src/components/Hero.astro` - Hero section
- `src/components/Footer.astro` - Footer with links
- etc.

Modify any component freely. The layout structure is isolated to prevent duplication.

---

## 🛠️ Available Commands

```bash
# Development server
npm run dev

# Build for production
npm run build

# Preview production build
npm run preview

# Deploy to Vercel
vercel --prod

# Deploy with auto-alias
vercel alias set portfolio-youssef-el-bouazzaoui.vercel.app
```

---

## 🌍 Deployment

### Deploy to Vercel

1. **Login to Vercel**

   ```bash
   vercel login
   ```

2. **Deploy**

   ```bash
   vercel --prod
   ```

3. **Set custom domain** (optional)
   ```bash
   vercel alias set portfolio-youssef-el-bouazzaoui.vercel.app
   ```

### Environment Variables

Create a `.env.local` file if needed (optional for this static site):

```
# Example (not required for static portfolio)
PUBLIC_ANALYTICS_ID=your_id
```

---

## 📂 Project Structure

```
portfolio/
├── src/
│   ├── components/        # Reusable UI components
│   │   ├── Header.astro
│   │   ├── Hero.astro
│   │   ├── Skills.astro
│   │   ├── Education.astro
│   │   ├── Projects.astro
│   │   ├── Contact.astro
│   │   ├── Footer.astro
│   │   ├── AiAssistant.astro
│   │   ├── ResumeExport.astro
│   │   └── BackToTop.astro
│   ├── layouts/
│   │   └── BaseLayout.astro  # Main wrapper with global styles
│   ├── pages/
│   │   └── index.astro       # Main portfolio page
│   ├── data/
│   │   └── portfolio.ts      # ⭐ CENTRALIZED DATA - Edit this!
│   ├── utils/
│   │   └── icons.ts          # Lucide icon mappings
│   └── styles/
│       └── global.css        # Global styles (minimal, mostly in components)
├── public/                   # Static assets
├── astro.config.mjs          # Astro configuration
├── tsconfig.json             # TypeScript configuration
├── package.json              # Dependencies
├── vercel.json               # Vercel deployment config
├── .gitignore
└── README.md
```

---

## 🎓 Built With

- **[Astro](https://astro.build)** - Static site generator
- **[TypeScript](https://www.typescriptlang.org)** - Type safety
- **[Tailwind CSS](https://tailwindcss.com)** - Utility-first styling
- **[Lucide Icons](https://lucide.dev)** - Beautiful SVG icons
- **[jsPDF](https://github.com/parallax/jsPDF)** - PDF generation
- **[docx](https://github.com/dolanmiu/docx)** - Word document generation
- **[Vercel](https://vercel.com)** - Hosting & deployment
- **[Formsubmit](https://formsubmit.co)** - Contact form backend

---

## 📱 Responsive Design

The portfolio is fully responsive:

- **Mobile** (< 640px) - Single column, optimized touch
- **Tablet** (640px - 1024px) - Two columns, readable fonts
- **Desktop** (> 1024px) - Full multi-column layouts

Test with Chrome DevTools: `Shift + Ctrl + M` (Windows/Linux) or `Cmd + Shift + M` (Mac)

---

## ♿ Accessibility

- ✅ Semantic HTML structure
- ✅ ARIA labels on interactive elements
- ✅ Skip link for keyboard navigation
- ✅ Focus-visible styles
- ✅ Color contrast compliance
- ✅ Mobile-friendly tap targets

---

## 📊 Performance

- **Static generation** - Pre-built HTML (fast)
- **No client-side overhead** - Minimal JavaScript
- **Lazy loaded images** - Optimized loading
- **Code splitting** - Heavy libraries loaded on demand (PDF/Word export)
- **Vercel CDN** - Global edge caching

**Lighthouse scores:**

- Performance: 90+
- Accessibility: 95+
- Best Practices: 95+
- SEO: 100+

---

## 🔒 Privacy Policy

This portfolio doesn't track personal data beyond Vercel Analytics (aggregated, anonymous).

Contact form messages are sent via [formsubmit.co](https://formsubmit.co) - review their privacy policy as well.

---

## 📝 License

MIT License - Feel free to use this template for your own portfolio!

---

## 🤝 Contributing

Found a bug or want to suggest features? Feel free to open an issue or pull request.

---

## 👤 Author

**Youssef EL BOUAZZAOUI**

- 🔗 GitHub: [@yelbouazzaoui-beep](https://github.com/yelbouazzaoui-beep)
- 💼 LinkedIn: [youssef-el-bouazzaoui](https://linkedin.com/in/youssef-el-bouazzaoui-3938083b5)
- 📧 Email: [you2007b@gmail.com](mailto:you2007b@gmail.com)

---

## 🙏 Acknowledgments

- Inspired by modern design trends (glassmorphism, smooth animations)
- Built with ❤️ and ☕ coffee

---

**Happy Coding! 🚀**

For questions or issues, reach out via email or LinkedIn.
