.. raw:: html

   <table style="text-align: justify; width: 100%;" background="/images/bgcolormain.png" border="0" cellpadding="1" cellspacing="1"><tr><td style="vertical-align: top;">

.. Include:: introduction/index-abstract.pl

`Wi�cej... <introduction/index>`__

.. raw:: html

   </td></tr></tbody></table><br>


.. raw:: html

   <table style="width: 100%; text-align: justify; margin-left: auto; margin-right: auto;" background="/images/bgcolormain.png" border="0" cellpadding="1" cellspacing="1"><tr><td>

.. Include:: download-abstract.en

`Wi�cej... <download>`__

.. raw:: html

   </td></tr></table>


.. raw:: html

   <table style="width: 100%; text-align: justify; margin-left: auto; margin-right: auto;" background="/images/bgcolormain.png" border="0" cellpadding="1" cellspacing="1"><tr><td>

Commits
=======

.. raw:: html

   <?php include("../rsfeed/commits.php"); ?></td></tr></table>


.. raw:: html

   <table style="width: 100%; text-align: justify; margin-left: auto; margin-right: auto;" border="0" cellpadding="1" cellspacing="1"><tr><td>

.. Include:: news/index.pl

.. raw:: html

   </td></tr></table><br>


.. raw:: html

   <td style="width: 243px; vertical-align: top;">
   <!-- The direct downloads block is disabled so that users go to the downloads section where they should learn about using distribution instead of nightly
   <table style="text-align: justify; width:100%;" background="/images/bgcolorright.png" border="0" cellpadding="1" cellspacing="1"><tr><td>
   <?php if ($win_ie56) { echo "<img alt=\"Direct download Icon\" src=\"/images/directdownloadicon.gif\" align=\"middle\">";} 
   else { echo "<img alt=\"Direct download Icon\" src=\"/images/directdownloadicon.png\" align=\"middle\">";} ?>Direct Downloads:<br>
   <img style="width: 238px; height: 2px;" alt="spacer" src="/images/sidespacer.png"><br>
   Nocne buildy budowane s� automatycznie ka�nej nocy z najnowszych �r�de�. Aby wypr�bowa� Live CD AROSa, �ci�gnij "boot ISO" dla twojej platformy.<br><br>
   <?php virtual("/cgi-bin/files2") ?> <br></td></tr></tbody></table>-->

   <table style="text-align: justify; width: 100%;" background="/images/bgcolorright.png" border="0" cellpadding="1" cellspacing="1"><tr><td>
   <?php if ($win_ie56) { echo "<img alt=\"Archive Icon\" src=\"/images/archivedownloadicon.gif\" align=\"middle\">"; } 
   else { echo "<img alt=\"Archive Icon\" src=\"/images/archivedownloadicon.png\" align=\"middle\">"; } ?>
   Najnowsze uploady do Archiwum:<br><img style="width: 238px; height: 2px;" alt="spacer" src="/images/sidespacer.png"><br>
   <a href=http://archives.aros-exec.org>Archiwa AROSa </a> zawieraj� najnowsze aplikacje, grafiki i dodatkow� dokumentacj� przygotowan� przez spo�eczno�� AROS.<br><br>
   <?php include("../rsfeed/archives.php"); ?><br></td></tr></table>

   <table style="text-align: justify; width: 100%;" background="/images/bgcolorright.png" border="0" cellpadding="1" cellspacing="1"><tr><td>
   <?php if ($win_ie56) { echo "<img alt=\"Community Icon\" src=\"/images/communityicon.gif\" align=\"middle\">"; } 
   else { echo "<img alt=\"Community Icon\" src=\"/images/communityicon.png\" align=\"middle\">"; } ?> 
   Najnowsze posty na AROS-EXEC:<br><img style="width: 238px; height: 2px;" alt="spacer" src="/images/sidespacer.png"><br>
   <a href=http://aros-exec.org>AROS-EXEC</a> jest g��wnym serwisem spo�eczno�ci AROS. Odwied� go je�li szukasz pomocy lub chcesz sie dowiedzie� wi�cej o systemie AROS.<br><br>
   <?php include("../rsfeed/aeforum.php"); ?><br></td></tr></tbody></table>

   <table style="width: 100%; text-align: justify; margin-left: auto; margin-right: auto;" background="/images/bgcolorright.png" border="0" cellpadding="1" cellspacing="1"><tr><td style="vertical-align: top;">
   <?php if ($win_ie56) { echo "<img alt=\"Syndication Icon\" src=\"/images/rssicon1.gif\" align=\"middle\">"; } else { echo "<img alt=\"Syndication Icon\" src=\"/images/rssicon1.png\" align=\"middle\">"; } ?>
   Kana�y RSS:<br><img style="width: 177px; height: 2px;" alt="spacer" src="/images/sidespacer.png"><br>
   <?php  include("../rsfeed/synfeed.php");  ?><br></td></tr></table>
   </td></tr></table>
