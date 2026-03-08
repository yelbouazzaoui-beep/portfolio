#!/usr/bin/env pwsh

# ============================================
# PORTFOLIO YOUSSEF - COMMANDES SUCCINCTES
# ============================================
# À exécuter dans PowerShell (admin recommandé)

Write-Host "🎉 Portfolio Youssef PRÊT!`n" -ForegroundColor Green

# Vérifier les outils
Write-Host "1. VÉRIFIER LES OUTILS" -ForegroundColor Cyan
Write-Host "   - Node.js v24.13: $(node --version)"
Write-Host "   - npm: $(npm --version)`n"

# Git
Write-Host "2. INITIALISER GIT" -ForegroundColor Cyan
Write-Host "   git init"
Write-Host "   git add ."
Write-Host "   git commit -m 'Initial: Complete portfolio'`n"

# GitHub
Write-Host "3. CRÉER DÉPÔT GITHUB" -ForegroundColor Cyan
Write-Host "   gh auth login"
Write-Host "   gh repo create portfolio-youssef --source=. --push`n"

# Vercel
Write-Host "4. DÉPLOYER SUR VERCEL" -ForegroundColor Cyan
Write-Host "   npm install -g vercel"
Write-Host "   vercel login"
Write-Host "   vercel --prod --yes`n"

# Alias
Write-Host "5. CONFIGURER L'ALIAS" -ForegroundColor Cyan
Write-Host "   vercel alias set portfolio-youssef-el-bouazzaoui.vercel.app`n"

# Final
Write-Host "✅ RÉSULTAT:" -ForegroundColor Green
Write-Host "   https://portfolio-youssef-el-bouazzaoui.vercel.app`n"

Write-Host "📚 DOCUMENTATION:" -ForegroundColor Yellow
Write-Host "   - PROJECT_SUMMARY_FR.md (résumé complet)"
Write-Host "   - DEPLOYMENT_FR.md (guide de déploiement)"
Write-Host "   - README.md (documentation générale)`n"
