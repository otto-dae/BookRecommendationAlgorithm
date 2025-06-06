<a id="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]


<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/otto-dae/BookRecommendationAlgorithm">
    <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR9o9NlESDJDZsD51LdGdMt1miatn40Ktfxnw&s" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Book Recommendation algorithm</h3>
  <p align="center"> 
    <a href="https://docs.google.com/document/d/1zmMKIbaKBjm5JbrIW5RPzc1xCFaNuNt4Kg1RIb8TNJ0/edit?usp=sharing"><strong>Explore the documentation »</strong></a>
    <br />
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#get-the-code">Get the code</a></li>
        <li><a href="#compile-and-run">Compile and run</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#diagram">Diagram</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

![Product Name Screen Shot][product-screenshot]
This repository is used to save and manage our algorithm and its structure. If you have any questions, please contact the owner (otto-dae).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With


* ![C++][C++]
* ![Git][Git]
* ![Docker][Docker]
* ![GitHub][GitHub]
* ![VSCode][VSCode]
* ![StackOverFlow][StackOverFlow]



<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Get the code

To get the project up and running do:
  ```bash
  git clone https://github.com/otto-dae/BookRecommendationAlgorithm.git
  ```

### Compile and run

For properly running this project, having <a href=https://www.docker.com/get-started/>docker/docker desktop</a> is a must.

Navigate to the project's root directory

Also, this project has connection to a DB, you'll have to ask the owner for the credentials, this is just a Uni project, not much thought went behind security or env variables.

Using Docker
1. Write in your terminal in the project's root directory to build the docker image
   ```
    docker build -t cpp-postgres .
   ```
2. Run the docker image with
   ```
   docker run -it cpp-postgres
   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

When running the code you'll be prompted to choose how to filter/search a book, by title, by category or by category and sub-category.

After choosing an option of category or sub-category when given the choice, the program will do a basic sum, search and sort algorithm based on matches between your choices and the available books.

_For more detail on how the program works, please refer to the [Documentation](hhttps://docs.google.com/document/d/1zmMKIbaKBjm5JbrIW5RPzc1xCFaNuNt4Kg1RIb8TNJ0/edit?usp=sharing)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Diagram
A visual interpratation of the program.

<img src="resources/Diagram/BookAlgorithm.png" alt="Diagram"></img>

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/otto-dae/BookRecommendationAlgorithm.svg?style=for-the-badge
[contributors-url]: https://github.com/otto-dae/BookRecommendationAlgorithm/graphs/contributors


[C++]: https://img.shields.io/badge/-C++-blue?logo=cplusplus
[GitHub]: https://img.shields.io/badge/GitHub-%23121011.svg?logo=github&logoColor=white
[product-screenshot]: https://art.ngfiles.com/images/2891000/2891329_citrusmillie_the-willow-library-pixel-art-wallpaper.png?f1669689511
[Git]: https://img.shields.io/badge/Git-F05032?logo=git&logoColor=fff
[VSCode]: https://custom-icon-badges.demolab.com/badge/Visual%20Studio%20Code-0078d7.svg?logo=vsc&logoColor=white
[StackOverFlow]: https://img.shields.io/badge/-Stack%20Overflow-FE7A16?logo=stack-overflow&logoColor=white
[Docker]: https://img.shields.io/badge/Docker-2496ED?logo=docker&logoColor=fff