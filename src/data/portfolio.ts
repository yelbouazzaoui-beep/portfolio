/**
 * Fichier de données centralisé contenant toutes les informations du portfolio
 * C'est le seul fichier à modifier pour mettre à jour le contenu du portfolio
 */

export interface PersonalInfo {
  firstName: string;
  lastName: string;
  title: string;
  subtitle: string;
  email: string;
  phone?: string;
  location: string;
  avatarUrl: string;
  availability: 'stage' | 'opportunity' | 'collaboration' | 'remote';
  availabilityLabel: string;
}

export interface Skill {
  name: string;
  icon: string;
  category: string;
  proficiency?: 'beginner' | 'intermediate' | 'advanced' | 'expert';
}

export interface Education {
  school: string;
  schoolUrl: string;
  degree: string;
  field: string;
  startDate: string;
  endDate?: string;
  isCurrent: boolean;
  description?: string;
}

export interface Experience {
  company: string;
  companyUrl?: string;
  position: string;
  type: 'stage' | 'emploi' | 'freelance' | 'volontariat';
  startDate: string;
  endDate?: string;
  isCurrent: boolean;
  description: string;
}

export interface Publication {
  title: string;
  journal: string;
  year: number;
  doi?: string;
  url?: string;
  authors: string[];
  isFirstAuthor: boolean;
}

export interface Certification {
  title: string;
  issuer: string;
  issuerUrl?: string;
  date: string;
  credentialUrl?: string;
  credentialId?: string;
  skills?: string[];
  category?: string;
}

export interface Project {
  title: string;
  description: string;
  technologies: string[];
  link?: string;
  github?: string;
  image?: string;
  featured?: boolean;
}

export interface SocialLink {
  name: string;
  icon: string;
  url: string;
  label: string;
}

// ============== DONNÉES PERSONNELLES ==============
const personalInfo: PersonalInfo = {
  firstName: 'Youssef',
  lastName: 'EL BOUAZZAOUI',
  title: 'Computer Science Student',
  subtitle: 'Aspiring Software Developer',
  email: 'you2007b@gmail.com',
  location: 'Morocco',
  avatarUrl: 'https://avatars.githubusercontent.com/u/yelbouazzaoui-beep?v=4',
  availability: 'stage',
  availabilityLabel: 'Disponible pour un stage'
};

// ============== STATISTIQUES CLÉS ==============
const stats = {
  projectsCompleted: 8,
  technologiesMastered: 12,
  certificatesEarned: 5,
  yearsStudying: 3
};

// ============== COMPÉTENCES TECHNIQUES ==============
const technicalSkills: Skill[] = [
  // Web Development
  { name: 'JavaScript', icon: 'Code2', category: 'Web Development', proficiency: 'expert' },
  { name: 'TypeScript', icon: 'Code2', category: 'Web Development', proficiency: 'advanced' },
  { name: 'React', icon: 'Code2', category: 'Web Development', proficiency: 'advanced' },
  { name: 'Astro', icon: 'Code2', category: 'Web Development', proficiency: 'advanced' },
  { name: 'HTML5', icon: 'Code2', category: 'Web Development', proficiency: 'expert' },
  { name: 'CSS3', icon: 'Code2', category: 'Web Development', proficiency: 'expert' },
  { name: 'Tailwind CSS', icon: 'Code2', category: 'Web Development', proficiency: 'advanced' },
  { name: 'Node.js', icon: 'Server', category: 'Backend', proficiency: 'advanced' },
  { name: 'Express.js', icon: 'Server', category: 'Backend', proficiency: 'intermediate' },
  // Tools & Platforms
  { name: 'Git', icon: 'GitBranch', category: 'Tools & Platforms', proficiency: 'advanced' },
  { name: 'GitHub', icon: 'GitBranch', category: 'Tools & Platforms', proficiency: 'advanced' },
  { name: 'VS Code', icon: 'Code', category: 'Tools & Platforms', proficiency: 'expert' }
];

// ============== COMPÉTENCES SOFT ==============
const softSkills = [
  { name: 'Communication', icon: 'MessageCircle', description: 'Excellente capacité à communiquer et collaborer en équipe' },
  { name: 'Problem Solving', icon: 'Lightbulb', description: 'Approche analytique pour résoudre les défis complexes' },
  { name: 'Adaptability', icon: 'Zap', description: 'Rapide à apprendre et s\'adapter aux nouvelles technologies' },
  { name: 'Time Management', icon: 'Clock', description: 'Organisation et gestion efficace des priorités' },
  { name: 'Team Work', icon: 'Users', description: 'Collaboration active au sein d\'équipes multidisciplinaires' }
];

// ============== PARCOURS ACADÉMIQUE ==============
const education: Education[] = [
  {
    school: 'ESISA - École Supérieure d\'Ingénierie en Sciences Appliquées',
    schoolUrl: 'https://www.esisa.ma',
    degree: 'Ingénieur',
    field: 'Computer Science & Software Engineering',
    startDate: '2022',
    endDate: '2025',
    isCurrent: true,
    description: 'Formation d\'ingénieur spécialisée en informatique avec focus sur le développement logiciel, les bases de données et les systèmes distribués.'
  }
];

// ============== EXPÉRIENCE PROFESSIONNELLE ==============
const experiences: Experience[] = [];
// Expérience optionnelle - laisser vide si pas d'expérience

// ============== PUBLICATIONS ==============
const publications: Publication[] = [];
// Publications optionnelles - laisser vide si pas de publications

// ============== CERTIFICATIONS ==============
const certifications: Certification[] = [];
// Certifications optionnelles - laisser vide si pas de certifications

// ============== PROJETS ==============
const projects: Project[] = [
  {
    title: 'Portfolio Web Astro',
    description: 'Portfolio personnel moderne et responsive construit avec Astro, TypeScript et Tailwind CSS.',
    technologies: ['Astro', 'TypeScript', 'Tailwind CSS', 'ShadcnUI'],
    link: '#projects',
    featured: true
  },
  {
    title: 'Weather App',
    description: 'Application météo interactive utilisant une API publique avec interface moderne et notifications en temps réel.',
    technologies: ['React', 'JavaScript', 'API REST', 'CSS3'],
    github: '#',
    featured: true
  },
  {
    title: 'Task Manager App',
    description: 'Gestionnaire de tâches avec localStorage, catégorisation et système de filtrage avancé.',
    technologies: ['React', 'TypeScript', 'Tailwind CSS'],
    github: '#'
  },
  {
    title: 'E-commerce Platform',
    description: 'Plateforme e-commerce de démonstration avec panier, paiement simulé et gestion des produits.',
    technologies: ['React', 'Node.js', 'MongoDB', 'Express.js'],
    github: '#'
  },
  {
    title: 'Blog Personnel',
    description: 'Blog technique pour partager mes apprentissages en développement web et informatique.',
    technologies: ['Astro', 'Markdown', 'CSS3'],
    link: '#'
  },
  {
    title: 'API REST',
    description: 'API RESTful pour gestion de ressources avec authentification JWT et documentation Swagger.',
    technologies: ['Node.js', 'Express.js', 'JWT', 'Swagger'],
    github: '#'
  }
];

// ============== LIENS SOCIAUX ==============
const socialLinks: SocialLink[] = [
  {
    name: 'GitHub',
    icon: 'Github',
    url: 'https://github.com/yelbouazzaoui-beep',
    label: 'GitHub Profile'
  },
  {
    name: 'LinkedIn',
    icon: 'Linkedin',
    url: 'https://www.linkedin.com/in/youssef-el-bouazzaoui-3938083b5',
    label: 'LinkedIn Profile'
  },
  {
    name: 'Email',
    icon: 'Mail',
    url: 'mailto:you2007b@gmail.com',
    label: 'Email'
  }
];

// ============== SECTIONS ACTIVES ==============
// Généré automatiquement basé sur les données présentes
export const activeSections = {
  about: true,
  skills: true,
  education: education.length > 0,
  experience: experiences.length > 0,
  publications: publications.length > 0,
  certifications: certifications.length > 0,
  projects: projects.length > 0,
  contact: true
};

// ============== NAVIGATION ==============
export function generateNavItems() {
  const items = [
    { label: 'Accueil', href: '#home', icon: 'Home' }
  ];

  if (activeSections.about) items.push({ label: 'À Propos', href: '#about', icon: 'User' });
  if (activeSections.skills) items.push({ label: 'Compétences', href: '#skills', icon: 'Zap' });
  if (activeSections.education) items.push({ label: 'Éducation', href: '#education', icon: 'GraduationCap' });
  if (activeSections.experience) items.push({ label: 'Expérience', href: '#experience', icon: 'Briefcase' });
  if (activeSections.publications) items.push({ label: 'Publications', href: '#publications', icon: 'BookOpen' });
  if (activeSections.certifications) items.push({ label: 'Certifications', href: '#certifications', icon: 'Award' });
  if (activeSections.projects) items.push({ label: 'Projets', href: '#projects', icon: 'Code' });
  items.push({ label: 'Contact', href: '#contact', icon: 'Mail' });

  return items;
}

// ============== EXPORT ==============
export {
  personalInfo,
  stats,
  technicalSkills,
  softSkills,
  education,
  experiences,
  publications,
  certifications,
  projects,
  socialLinks
};
