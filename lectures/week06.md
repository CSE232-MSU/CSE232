---
title: Week 06
---

<span style="color:red">This document is currently being updated!</span>


# Week 06
Sample exam questions to be provided later.


## Exceptions and Invariants
* Reading: Sections 4.1, 4.2, and 4.3
* [Lecture slides (Exceptions and Invariants)](https://docs.google.com/presentation/d/1pdTEu_iQnLfTmfessF_A-_FFIjLt5nYREQ6K-42bWC0/edit?usp=sharing)

<div align="center">
<iframe id="kaltura_player" src="https://cdnapisec.kaltura.com/p/811482/sp/81148200/embedIframeJs/uiconf_id/27551951/partner_id/811482?iframeembed=true&playerId=kaltura_player&entry_id=1_etjaum9c&flashvars[streamerType]=auto&amp;flashvars[localizationCode]=en&amp;flashvars[sideBarContainer.plugin]=true&amp;flashvars[sideBarContainer.position]=left&amp;flashvars[sideBarContainer.clickToClose]=true&amp;flashvars[chapters.plugin]=true&amp;flashvars[chapters.layout]=vertical&amp;flashvars[chapters.thumbnailRotator]=false&amp;flashvars[streamSelector.plugin]=true&amp;flashvars[EmbedPlayer.SpinnerTarget]=videoHolder&amp;flashvars[dualScreen.plugin]=true&amp;flashvars[hotspots.plugin]=1&amp;flashvars[Kaltura.addCrossoriginToIframe]=true&amp;&wid=1_m7p9flqh" width="640" height="396" allowfullscreen webkitallowfullscreen mozAllowFullScreen allow="autoplay *; fullscreen *; encrypted-media *" sandbox="allow-downloads allow-forms allow-same-origin allow-scripts allow-top-navigation allow-pointer-lock allow-popups allow-modals allow-orientation-lock allow-popups-to-escape-sandbox allow-presentation allow-top-navigation-by-user-activation" frameborder="0" title="CSE 232 - Exceptions and Invariants"></iframe>
</div>

## Error-Handling Alternatives and Assertions
* Reading: Sections 4.4 and 4.5
* [Lecture slides (Error-Handling Alternatives and Assertions)](https://docs.google.com/presentation/d/1NEC2M_6X-WCZVfHvd3yake4RYhJ09oGfDqURzKPQmbs/edit?usp=sharing)

<div align="center">
<iframe id="kaltura_player" src="https://cdnapisec.kaltura.com/p/811482/sp/81148200/embedIframeJs/uiconf_id/27551951/partner_id/811482?iframeembed=true&playerId=kaltura_player&entry_id=1_tiae26kd&flashvars[streamerType]=auto&amp;flashvars[localizationCode]=en&amp;flashvars[sideBarContainer.plugin]=true&amp;flashvars[sideBarContainer.position]=left&amp;flashvars[sideBarContainer.clickToClose]=true&amp;flashvars[chapters.plugin]=true&amp;flashvars[chapters.layout]=vertical&amp;flashvars[chapters.thumbnailRotator]=false&amp;flashvars[streamSelector.plugin]=true&amp;flashvars[EmbedPlayer.SpinnerTarget]=videoHolder&amp;flashvars[dualScreen.plugin]=true&amp;flashvars[hotspots.plugin]=1&amp;flashvars[Kaltura.addCrossoriginToIframe]=true&amp;&wid=1_behydup6" width="640" height="396" allowfullscreen webkitallowfullscreen mozAllowFullScreen allow="autoplay *; fullscreen *; encrypted-media *" sandbox="allow-downloads allow-forms allow-same-origin allow-scripts allow-top-navigation allow-pointer-lock allow-popups allow-modals allow-orientation-lock allow-popups-to-escape-sandbox allow-presentation allow-top-navigation-by-user-activation" frameborder="0" title="CSE 232 - Error-Handling Alternatives and Assertions"></iframe>
</div>


## Unix Skills
* Reading: None
* Topics: Pagers, Manuals, History, Wildcards
* [Lecture slides (Unix Skills)](https://docs.google.com/presentation/d/1oOPEVgG5ZK8g-aU2s-fTOUmPtCdKqgdQJfn_BsmbLsQ/edit?usp=sharing)

<div align="center">
<iframe id="kaltura_player" src="https://cdnapisec.kaltura.com/p/811482/sp/81148200/embedIframeJs/uiconf_id/27551951/partner_id/811482?iframeembed=true&playerId=kaltura_player&entry_id=1_7vtgiaji&flashvars[streamerType]=auto&amp;flashvars[localizationCode]=en&amp;flashvars[sideBarContainer.plugin]=true&amp;flashvars[sideBarContainer.position]=left&amp;flashvars[sideBarContainer.clickToClose]=true&amp;flashvars[chapters.plugin]=true&amp;flashvars[chapters.layout]=vertical&amp;flashvars[chapters.thumbnailRotator]=false&amp;flashvars[streamSelector.plugin]=true&amp;flashvars[EmbedPlayer.SpinnerTarget]=videoHolder&amp;flashvars[dualScreen.plugin]=true&amp;flashvars[hotspots.plugin]=1&amp;flashvars[Kaltura.addCrossoriginToIframe]=true&amp;&wid=1_earcib8j" width="640" height="396" allowfullscreen webkitallowfullscreen mozAllowFullScreen allow="autoplay *; fullscreen *; encrypted-media *" sandbox="allow-downloads allow-forms allow-same-origin allow-scripts allow-top-navigation allow-pointer-lock allow-popups allow-modals allow-orientation-lock allow-popups-to-escape-sandbox allow-presentation allow-top-navigation-by-user-activation" frameborder="0" title="CSE 232 - Unix Skills"></iframe>
</div>


<span style="color:red">Old Content Below!</span>

# Week 06

[Lecture slides (Vectors)](https://docs.google.com/presentation/d/1N1ajnLs6HaTrm4-4HN2-XCEtO8mszlv-xau0Fyqo8YM/edit?usp=sharing)

[Lecture slides (Exceptions and String Stream)](https://docs.google.com/presentation/d/1xGb8cJtcwnxHDfxJWAbb7kcYIOU6LZ2SOp1zojxw44c/edit?usp=sharing)

### Vectors

[10.1-vector.cpp](week06/10.1-vector.cpp)

[10.2-moreVector.cpp](week06/10.2-moreVector.cpp)

[10.3-sieve.cpp](week06/10.3-sieve.cpp)

[10.4-split.cpp](week06/10.4-split.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/VzZFKoL_qxk" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

**Note**: minor correction; calling the `vector` constructor with one `int` argument (n) will create a vector of size n with each element default initialized (0 for numbers, empty for strings, etc.). So `std::vector<int> vec(5);` will result in a vector of 5 zeros.

Secondly, the capacity of a vector is only guarenteed to be equal or greater than the size. Its exact value (at constructor or later) is determined by the memory allocation used in a particular C++ implementation.

### 2D Vectors

[10.5-2d.cpp](week06/10.5-2d.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/K7K153h3rWA" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### Range Based For Loops

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/k5vOH8SmNOQ" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### Exceptions

[11.1-assert.cpp](week06/11.1-assert.cpp)

[11.2-try-substr.cpp](week06/11.2-try-substr.cpp)

[11.3-stol.cpp](week06/11.3-stol.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/L3_oy_LZ9_M" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>

### String Streams

[11.5-sstream.cpp](week06/11.5-sstream.cpp)

[11.6-istringstream.cpp](week06/11.6-istringstream.cpp)

[11.7-ostringstream.cpp](week06/11.7-ostringstream.cpp)

<div align="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/LFvD_Bl_4Rg" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>
