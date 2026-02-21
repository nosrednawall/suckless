;;; $DOOMDIR/config.el -*- lexical-binding: t; -*-

;; Place your private configuration here! Remember, you do not need to run 'doom
;; sync' after modifying this file!


;; Some functionality uses this to identify you, e.g. GPG configuration, email
;; clients, file templates and snippets. It is optional.
;; (setq user-full-name "John Doe"
;;       user-mail-address "john@doe.com")

;; Doom exposes five (optional) variables for controlling fonts in Doom:
;;
;; - `doom-font' -- the primary font to use
;; - `doom-variable-pitch-font' -- a non-monospace font (where applicable)
;; - `doom-big-font' -- used for `doom-big-font-mode'; use this for
;;   presentations or streaming.
;; - `doom-symbol-font' -- for symbols
;; - `doom-serif-font' -- for the `fixed-pitch-serif' face
;;
;; See 'C-h v doom-font' for documentation and more examples of what they
;; accept. For example:
;;
;;(setq doom-font (font-spec :family "Fira Code" :size 12 :weight 'semi-light)
;;      doom-variable-pitch-font (font-spec :family "Fira Sans" :size 13))
;;
;; If you or Emacs can't find your font, use 'M-x describe-font' to look them
;; up, `M-x eval-region' to execute elisp code, and 'M-x doom/reload-font' to
;; refresh your font settings. If Emacs still can't find your font, it likely
;; wasn't installed correctly. Font issues are rarely Doom issues!

;; There are two ways to load a theme. Both assume the theme is installed and
;; available. You can either set `doom-theme' or manually load a theme with the
;; `load-theme' function. This is the default:
(setq doom-theme 'doom-gruvbox)

;; This determines the style of line numbers in effect. If set to `nil', line
;; numbers are disabled. For relative line numbers, set this to `relative'.
(setq display-line-numbers-type t)

;; If you use `org' and don't want your org files in the default location below,
;; change `org-directory'. It must be set before org loads!
(setq org-directory "~/org/")


;; Whenever you reconfigure a package, make sure to wrap your config in an
;; `after!' block, otherwise Doom's defaults may override your settings. E.g.
;;
;;   (after! PACKAGE
;;     (setq x y))
;;
;; The exceptions to this rule:
;;
;;   - Setting file/directory variables (like `org-directory')
;;   - Setting variables which explicitly tell you to set them before their
;;     package is loaded (see 'C-h v VARIABLE' to look up their documentation).
;;   - Setting doom variables (which start with 'doom-' or '+').
;;
;; Here are some additional functions/macros that will help you configure Doom.
;;
;; - `load!' for loading external *.el files relative to this one
;; - `use-package!' for configuring packages
;; - `after!' for running code after a package has loaded
;; - `add-load-path!' for adding directories to the `load-path', relative to
;;   this file. Emacs searches the `load-path' when you load packages with
;;   `require' or `use-package'.
;; - `map!' for binding new keys
;;
;; To get information about any of these functions/macros, move the cursor over
;; the highlighted symbol at press 'K' (non-evil users must press 'C-c c k').
;; This will open documentation for it, including demos of how they are used.
;; Alternatively, use `C-h o' to look up a symbol (functions, variables, faces,
;; etc).
;;
;; You can also try 'gd' (or 'C-c c d') to jump to their definition and see how
;; they are implemented.

(add-hook 'python-mode-hook #'lsp)
(add-hook 'jupyter-python-mode-hook #'lsp)

;; C-c v a  → escolhe venv com completing-read
(global-set-key (kbd "C-c v a") #'pyvenv-activate)
(global-set-key (kbd "C-c v d") #'pyvenv-deactivate)

;; Adiciona navegação entre os buffers, com as teclas Alt+Seytas
(when (fboundp 'windmove-default-keybindings)
  (windmove-default-keybindings))

(require 'multiple-cursors)
(global-set-key (kbd "C->") 'mc/mark-next-like-this)
(global-set-key (kbd "C-<") 'mc/mark-previous-like-this)
(global-set-key (kbd "C-c C-<") 'mc/mark-all-like-this)


(defun my-python-send-smart ()
  (interactive)
  (cond
   ;; 1) região ativa
   ((use-region-p)
    (python-shell-send-region (region-beginning) (region-end))
    (message "Sent region"))

   ;; 2) dentro de def/classe - envia função completa
   ((python-info-current-defun)
    (python-shell-send-defun nil)
    (message "Sent def/class"))

   ;; 3) linha atual
   (t
    (save-excursion
      (beginning-of-line)
      (skip-chars-forward " \t")          ; pula indentação
      (let ((bol-pos (point))             ; início da linha útil
            (line-contents (buffer-substring-no-properties
                           (line-beginning-position) (line-end-position))))

        ;; Verifica se é um cabeçalho (termina com :) E não é vazia
        (if (and (not (string-blank-p line-contents))
                 (string-suffix-p ":" line-contents))

            ;; --------- É CABEÇALHO -> manda BLOCO COMPLETO ----------
            (let ((start (point))
                  (initial-indent (current-indentation)))
              ;; Encontra o início do bloco (linha atual)
              (python-nav-beginning-of-defun)
              (when (< (point) start)
                ;; Vai para próxima linha se não estamos no início do bloco
                (python-nav-forward-statement))

              (let ((block-begin (point)))
                ;; Encontra o fim do bloco
                (python-nav-forward-sexp)
                (python-shell-send-region block-begin (point))
                (message "Sent complete block")))


          ;; --------- NÃO É CABEÇALHO -> manda LINHA ----------
          (python-shell-send-statement)
          (message "Sent statement")))

    ;; Anda uma linha no buffer de código
    )))
  (python-nav-forward-statement))

;; Configurações para melhor visualização
(with-eval-after-load 'python
  (setq python-shell-echo-input t
        python-shell-echo-input-ps1 t))

(add-hook 'python-mode-hook
          (lambda ()
            (local-set-key (kbd "<C-return>") #'my-python-send-smart)))


;; ============================================================================
;; Jupyter + Org mode configuration
;; ============================================================================

;; Configurar org-babel para jupyter (simplificado)
(with-eval-after-load 'org
  (org-babel-do-load-languages
   'org-babel-load-languages
   '((python . t)
     (jupyter . t)))

  (setq org-babel-default-header-args:jupyter-python
        '((:session . "py")
          (:kernel . "python3"))))

;; Desativar completion problemático do jupyter
(with-eval-after-load 'jupyter
  (setq jupyter-use-native-completion nil)
  (setq jupyter-completion-style 'nil))

;; Funções de exportação com tratamento de caminhos com espaços
(defun my/export-org-to-ipynb ()
  "Exportar arquivo org atual para formato Jupyter notebook."
  (interactive)
  (let* ((org-file (expand-file-name (buffer-file-name)))
         (ipynb-file (concat (file-name-sans-extension org-file) ".ipynb")))
    (if (executable-find "pandoc")
        (let ((command (format "pandoc -s \"%s\" -o \"%s\" --to ipynb --from org"
                              org-file ipynb-file)))
          (if (zerop (shell-command command))
              (message "✓ Exportado para %s" ipynb-file)
            (message "✗ Erro na exportação. Verifique o caminho.")))
      (message "✗ Pandoc não encontrado. Instale: sudo apt install pandoc"))))

(defun my/import-ipynb-to-org ()
  "Importar arquivo Jupyter notebook para org mode."
  (interactive)
  (let* ((ipynb-file (expand-file-name (read-file-name "Arquivo .ipynb: ")))
         (org-file (concat (file-name-sans-extension ipynb-file) ".org")))
    (if (executable-find "pandoc")
        (let ((command (format "pandoc -s \"%s\" -o \"%s\" --to org --from ipynb"
                              ipynb-file org-file)))
          (if (zerop (shell-command command))
              (progn
                (find-file org-file)
                (message "✓ Importado de %s" ipynb-file))
            (message "✗ Erro na importação. Verifique o arquivo.")))
      (message "✗ Pandoc não encontrado. Instale: sudo apt install pandoc"))))

;; Atalhos para org-mode (sem evil)
(with-eval-after-load 'org
  (define-key org-mode-map (kbd "C-c j e") #'org-babel-execute-maybe)
  (define-key org-mode-map (kbd "C-c j r") #'jupyter-run-repl)
  (define-key org-mode-map (kbd "C-c j i") #'org-toggle-inline-images)
  (define-key org-mode-map (kbd "C-c e p") #'my/export-org-to-ipynb)
  (define-key org-mode-map (kbd "C-c e i") #'my/import-ipynb-to-org))

;; Função para criar novo arquivo jupyter-org
(defun my/new-jupyter-org-file ()
  "Criar um novo arquivo org configurado para jupyter."
  (interactive)
  (let ((filename (read-string "Nome do arquivo: " nil nil "jupyter-notebook.org")))
    (find-file filename)
    (insert "#+TITLE: Jupyter Notebook\n")
    (insert "#+PROPERTY: header-args:jupyter-python :session py :kernel python3\n\n")
    (insert "#+begin_src jupyter-python\n")
    (insert "print('Hello Jupyter!')\n")
    (insert "#+end_src\n")
    (org-mode)))

(global-set-key (kbd "C-c n j") #'my/new-jupyter-org-file)

;; Configuração adicional para evitar erros de completion
(with-eval-after-load 'corfu
  (setq corfu-auto nil))  ; Desativar auto-completion temporariamente


;; Configurar yasnippet para org-mode
(use-package! yasnippet
  :config
  (yas-reload-all)
  (add-hook 'org-mode-hook #'yas-minor-mode))

;; Criar snippet personalizado para jupyter-python
(with-eval-after-load 'yasnippet
  (yas-define-snippets 'org-mode
   '(("jp" "#+begin_src jupyter-python :session py :kernel python3 :async yes\n$0\n#+end_src" "jupyter-python block")
     ("jpo" "#+begin_src jupyter-python :session py :kernel python3 :async yes :results output\n$0\n#+end_src" "jupyter-python output block")
     ("jpf" "#+begin_src jupyter-python :session py :kernel python3 :async yes :results file :file $1\n$2\n#+end_src" "jupyter-python file block"))))

