# Markdown Stylesheet

If you are planning on contributing to the repository with a new Markdown file, please adhere to the following style rules for sake of consistency and cleanliness.

GitHub recently released a dark mode for active users -- we are working under the assumption that the students __do not__ have a GitHub account, and so they will most likely see the website in its light mode (i.e., black text on white background).

Jump to section...
- [Naming](#1-naming)
- [Header Usage](#2-header-usage)
- [Text Emphasis](#3-text-emphasis)
- [Example Code](#4-example-code)
- [Lists](#5-lists)
- [Links](#6-links)
- [Images and Tables](#7-images-and-tables)
- [LaTeX](#8-latex)
- [Spelling and Grammar](#9-spelling-and-grammar)
- [Lab-Specific](#10-lab-specific)

### 1. Naming

Any and all Markdown files in the home directory of the repository should be _important_, and _general_. "General", in that, it should apply to *all* students participating in the course (this is most often logistical information). To denote its significance, beyond simply being in the home directory, its name should be fully capitalized LIKE_THIS.

Lab files, and other assignments that can be put into Markdown, should be fully lowercased. The number associated with it, (if enumerated), should have padding zeroes if it's a series of more than 9 occurrences.

### 2. Header Usage

Markdown translates parallely to HTML, and so I will be referring to Markdown syntax in terms of their HTML-equivalent tags.

H1 headers should only be used __once__ at the top of the document. __Do not use the H1 header anywhere else within the same document__.

H2 headers should denote _large_, and _significant_ sections of the document. They should be concise, and broad in their descriptions. You may create more than one, but don't over do it (on GitHub, H2 headers are displayed with a soft underline. A multitude of these underlines in a small amount of space can make the document look cluttered).

H3 headers should denote subsections that go into more detail of its parent H2 header. These can be used frequently, but should still contain a healthy amount of information before the next header appears.

H4 headers should *almost never* be used. It can be hard to differentiate between regularly-sized bold text and an H4 header depending on the context. Use H3 headers, unless the content to be placed has a _very_ strong hierarchical relationship to its parent header.

H5 and H6: don't even bother.

### 3. Text Emphasis

Italicization should be used when a word/phrase is being stressed within the sentence, or if the word/phrase is a new term that the student should be aware of for the rest of the document. I consider this different from when a word/phrase is deemed important for the student to know in the context of the course. If something is important to know for the _course_, you should bolden it.

Bold text should also be used to highlight asides or warnings, alike:

**Note**: this is an example note.

**Warning**: this is an example warning.

Do not bolden _and_ italicize a word/phrase -- it looks bad.

### 4. Example Code

When describing code, use backticks to surround a name, operator, or expression like `this` so that the student knows you're referring to code rather than an object of your sentence. __Do not use the "code" or "pre" HTML tags.__

If wanting to create a _block_ of code, use two sets of three backticks to wrap the example code, and note the language being used at the end of the top set for syntax highlighting.

<pre>
```c++
int main() {
    std::cout << "Hello world" << std::endl;
}
```
</pre>

No language should be specified when creating example output to the terminal (otherwise GitHub may highlight odd portions of it).

In examples of terminal _usage_, use `bash` as the language.

__Only use in-line code styling (`like this`) for code, and nothing else.__ File names should be represented in plaintext, like this.cpp. Unix commands may be represented as in-line code.

In regards to C++ code, specifically, have variable and class names represented like `this` (i.e., normally), and represent functions with empty parentheses at the end like `this()`. Most students will likely be following the "lower and under" convention for variable and function names, and the "CamelCase" convention for class names. So, placing the parentheses at the end can distinguish between a reference to some variable and some function.

### 5. Lists

Nested, unordered lists are okay. __Nested, ordered lists are not okay.__ Why? Because it looks disgusting. Example:

1. This is an ordered list
    1. This is a nested, ordered list element
    2. This is a nested, ordered list element
    3. This is a nested, ordered list element
    4. This is a nested, ordered list element

Because the font used by GitHub is not a [monospaced font](https://en.wikipedia.org/wiki/Monospaced_font), the roman numerals used to denote order in a nested, ordered list makes the spacing look strange. __Do not make nested, ordered lists.__

### 6. Links

Use in-line links as much as possible, [like this](https://github.com/braedynl/CSE232/blob/main/.assets/contributing/markdown-stylesheet.md#6-links). Only show the entire URL if needed to stress the URL's importance.

It's usually best to wrap the entire sentence in the in-line link for better visibility.

### 7. Images and Tables

Center them.

You'll have to wrap the image/table in a `<div>` tag, using the (outdated) `align` attribute. Example:

```html
<div align="center">
    <img src="hello.png">
</div>
```

Note that GitHub won't center the image/table in its preview, but it will be centered once committed.

### 8. LaTeX

GitHub's Markdown renderer does not inherently support LaTeX. There is, however, a hack-y way of creating LaTeX expressions in GitHub Markdown [as described in this gist](https://gist.github.com/a-rodin/fef3f543412d6e1ec5b6cf55bf197d7b).
 
[You can use this LaTeX to image converter that exploits the weird GitHub quirk (what I've been using for the most part).](https://tex-image-link-generator.herokuapp.com/) I have noticed that this tool struggles with representing matrices, however.

Use LaTeX when describing mathematical expressions. Note that, if you are writing the Markdown with a preview given by your text editor, your view may be different from what GitHub will render it as. Edit as necessary once you've pushed your Markdown to the repository.

__Note__: students that are using GitHub's dark mode, or have some sort of dark mode extension on their browser, may not be able to see the LaTeX expressions (because they're rendered in a black font, and would presumably be on a black/very dark background).

### 9. Spelling and Grammar

Fix your spelling and grammar mistakes by any means necessary. It can be distracting, and even disruptive to the student if the wording is atrocious and/or confusing. Get to the point fast, and don't get too technical.

I encourage use of contractions, but it's not too important that you use them over their expanded forms. Having many contractions can make the document easier to read, and can make it a bit shorter (even if by a small amount).

### 10. Lab-Specific

For lab documents, I've established the following conventions based on what the intent _seemed_ to be when first going through them myself. Many changes were made to better suit GitHub's Markdown rendering, as well.

#### Title Header

Use an H1 for the top-most header, with the format "Lab XX - Some Title". The rest of the header conventions are described above.

#### The Two Halves

(Almost) every lab has two portions: the Unix tutorial, and the coding segment. Denote the Unix tutorial with an H2 header and a descriptive title. The coding segment should _always_ be denoted by an H2 header as well, but with the text "Coding Assignment".

Both halves of the assignment can have a multitude of H3 subsections. The coding segment should have the following H3 subsections in most circumstances, however:
- Background
    - Describes the prerequisite knowledge necessary for the assignment
- Program Specifications
    - Describes what the student needs to create from the prerequisite knowledge discussed in the Background and lectures
- Assignment Notes
    - Describes some common problems the students may encounter, or hints at using particular tools that could be helpful
- Things to Think About
    - Miscellaneous notes on the reasons why a thing works, or what a thing does. Can be anything, really.

#### Graphics

If a visualization of some concept is necessary, you may insert a graphic taken from the internet. Please notify me (Braedyn), however, because I will make a version of that graphic in a way that cooperates better with GitHub's Markdown styling. The graphic taken from the internet will be a placeholder.

On a similar note, if the problem requires a lot of mathematical prerequisite, one should use LaTeX (discussed above) to express any and all formulae because it looks better than plaintext.

#### Checkpoints

Use the star emoji (⭐) to represent checkpoints of the lab assignment (where the student must verify with the TA that they're on the right track).

The star can be typed as `:star:` in the Markdown document for it to render as its proper emoji on the GitHub page (so you don't need to go to some website to copy-and-paste).
