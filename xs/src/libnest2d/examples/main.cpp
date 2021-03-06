#include <iostream>
#include <string>
#include <fstream>

//#define DEBUG_EXPORT_NFP

#include <libnest2d.h>

#include "tests/printer_parts.h"
#include "tools/benchmark.h"
#include "tools/svgtools.hpp"
//#include "tools/libnfpglue.hpp"

using namespace libnest2d;
using ItemGroup = std::vector<std::reference_wrapper<Item>>;

std::vector<Item>& _parts(std::vector<Item>& ret, const TestData& data)
{
    if(ret.empty()) {
        ret.reserve(data.size());
        for(auto& inp : data)
            ret.emplace_back(inp);
    }

    return ret;
}

std::vector<Item>& prusaParts() {
    static std::vector<Item> ret;
    return _parts(ret, PRINTER_PART_POLYGONS);
}

std::vector<Item>& stegoParts() {
    static std::vector<Item> ret;
    return _parts(ret, STEGOSAUR_POLYGONS);
}

std::vector<Item>& prusaExParts() {
    static std::vector<Item> ret;
    if(ret.empty()) {
        ret.reserve(PRINTER_PART_POLYGONS_EX.size());
        for(auto& p : PRINTER_PART_POLYGONS_EX) {
            ret.emplace_back(p.Contour, p.Holes);
        }
    }
    return ret;
}

void arrangeRectangles() {
    using namespace libnest2d;

    const int SCALE = 1000000;
//    const int SCALE = 1;
    std::vector<Rectangle> rects = {
        {80*SCALE, 80*SCALE},
        {60*SCALE, 90*SCALE},
        {70*SCALE, 30*SCALE},
        {80*SCALE, 60*SCALE},
        {60*SCALE, 60*SCALE},
        {60*SCALE, 40*SCALE},
        {40*SCALE, 40*SCALE},
        {10*SCALE, 10*SCALE},
        {10*SCALE, 10*SCALE},
        {10*SCALE, 10*SCALE},
        {10*SCALE, 10*SCALE},
        {10*SCALE, 10*SCALE},
        {5*SCALE, 5*SCALE},
        {5*SCALE, 5*SCALE},
        {5*SCALE, 5*SCALE},
        {5*SCALE, 5*SCALE},
        {5*SCALE, 5*SCALE},
        {5*SCALE, 5*SCALE},
        {5*SCALE, 5*SCALE},
        {20*SCALE, 20*SCALE}
       };

//    std::vector<Rectangle> rects = {
//        {20*SCALE, 10*SCALE},
//        {20*SCALE, 10*SCALE},
//        {20*SCALE, 20*SCALE},
//    };

//    std::vector<Item> input {
//        {{0, 0}, {0, 20*SCALE}, {10*SCALE, 0}, {0, 0}}
//    };

    std::vector<Item> crasher =
    {
        {
            {-5000000, 8954050},
            {5000000, 8954050},
            {5000000, -45949},
            {4972609, -568549},
            {3500000, -8954050},
            {-3500000, -8954050},
            {-4972609, -568549},
            {-5000000, -45949},
            {-5000000, 8954050},
        },
        {
            {-5000000, 8954050},
            {5000000, 8954050},
            {5000000, -45949},
            {4972609, -568549},
            {3500000, -8954050},
            {-3500000, -8954050},
            {-4972609, -568549},
            {-5000000, -45949},
            {-5000000, 8954050},
        },
        {
            {-5000000, 8954050},
            {5000000, 8954050},
            {5000000, -45949},
            {4972609, -568549},
            {3500000, -8954050},
            {-3500000, -8954050},
            {-4972609, -568549},
            {-5000000, -45949},
            {-5000000, 8954050},
        },
        {
            {-5000000, 8954050},
            {5000000, 8954050},
            {5000000, -45949},
            {4972609, -568549},
            {3500000, -8954050},
            {-3500000, -8954050},
            {-4972609, -568549},
            {-5000000, -45949},
            {-5000000, 8954050},
        },
        {
            {-5000000, 8954050},
            {5000000, 8954050},
            {5000000, -45949},
            {4972609, -568549},
            {3500000, -8954050},
            {-3500000, -8954050},
            {-4972609, -568549},
            {-5000000, -45949},
            {-5000000, 8954050},
        },
        {
            {-5000000, 8954050},
            {5000000, 8954050},
            {5000000, -45949},
            {4972609, -568549},
            {3500000, -8954050},
            {-3500000, -8954050},
            {-4972609, -568549},
            {-5000000, -45949},
            {-5000000, 8954050},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-9945219, -3065619},
            {-9781479, -2031780},
            {-9510560, -1020730},
            {-9135450, -43529},
            {-2099999, 14110899},
            {2099999, 14110899},
            {9135450, -43529},
            {9510560, -1020730},
            {9781479, -2031780},
            {9945219, -3065619},
            {10000000, -4110899},
            {9945219, -5156179},
            {9781479, -6190020},
            {9510560, -7201069},
            {9135450, -8178270},
            {8660249, -9110899},
            {8090169, -9988750},
            {7431449, -10802200},
            {6691309, -11542300},
            {5877850, -12201100},
            {5000000, -12771100},
            {4067369, -13246399},
            {3090169, -13621500},
            {2079119, -13892399},
            {1045279, -14056099},
            {0, -14110899},
            {-1045279, -14056099},
            {-2079119, -13892399},
            {-3090169, -13621500},
            {-4067369, -13246399},
            {-5000000, -12771100},
            {-5877850, -12201100},
            {-6691309, -11542300},
            {-7431449, -10802200},
            {-8090169, -9988750},
            {-8660249, -9110899},
            {-9135450, -8178270},
            {-9510560, -7201069},
            {-9781479, -6190020},
            {-9945219, -5156179},
            {-10000000, -4110899},
            {-9945219, -3065619},
        },
        {
            {-18000000, -1000000},
            {-15000000, 22000000},
            {-11000000, 26000000},
            {11000000, 26000000},
            {15000000, 22000000},
            {18000000, -1000000},
            {18000000, -26000000},
            {-18000000, -26000000},
            {-18000000, -1000000},
        },
    };

    std::vector<Item> proba = {
        {
            Rectangle(100, 2)
        },
        {
            Rectangle(100, 2)
        },
        {
            Rectangle(100, 2)
        },
        {
            Rectangle(10, 10)
        },
    };

    proba[0].rotate(Pi/3);
    proba[1].rotate(Pi-Pi/3);

//    std::vector<Item> input(25, Rectangle(70*SCALE, 10*SCALE));
    std::vector<Item> input;
    input.insert(input.end(), prusaParts().begin(), prusaParts().end());
//    input.insert(input.end(), prusaExParts().begin(), prusaExParts().end());
//    input.insert(input.end(), stegoParts().begin(), stegoParts().end());
//    input.insert(input.end(), rects.begin(), rects.end());
//    input.insert(input.end(), proba.begin(), proba.end());
//    input.insert(input.end(), crasher.begin(), crasher.end());

    Box bin(250*SCALE, 210*SCALE);

    auto min_obj_distance = static_cast<Coord>(0*SCALE);

    using Placer = NfpPlacer;
    using Packer = Arranger<Placer, FirstFitSelection>;

    Packer arrange(bin, min_obj_distance);

    Packer::PlacementConfig pconf;
    pconf.alignment = Placer::Config::Alignment::CENTER;
    pconf.starting_point = Placer::Config::Alignment::BOTTOM_LEFT;
    pconf.rotations = {0.0/*, Pi/2.0, Pi, 3*Pi/2*/};

    double norm_2 = std::nan("");
    pconf.object_function = [&bin, &norm_2](Placer::Pile pile, const Item& item,
            double /*area*/, double norm, double penality) {

        using pl = PointLike;

        auto bb = ShapeLike::boundingBox(pile);
        auto ibb = item.boundingBox();
        auto minc = ibb.minCorner();
        auto maxc = ibb.maxCorner();

        if(std::isnan(norm_2)) norm_2 = pow(norm, 2);

        // We get the distance of the reference point from the center of the
        // heat bed
        auto cc = bb.center();
        auto top_left = PointImpl{getX(minc), getY(maxc)};
        auto bottom_right = PointImpl{getX(maxc), getY(minc)};

        auto a = pl::distance(ibb.maxCorner(), cc);
        auto b = pl::distance(ibb.minCorner(), cc);
        auto c = pl::distance(ibb.center(), cc);
        auto d = pl::distance(top_left, cc);
        auto e = pl::distance(bottom_right, cc);

        auto area = bb.width() * bb.height() / norm_2;

        auto min_dist = std::min({a, b, c, d, e}) / norm;

        // The score will be the normalized distance which will be minimized,
        // effectively creating a circle shaped pile of items
        double score = 0.8*min_dist  + 0.2*area;

        // If it does not fit into the print bed we will beat it
        // with a large penality. If we would not do this, there would be only
        // one big pile that doesn't care whether it fits onto the print bed.
        if(!NfpPlacer::wouldFit(bb, bin)) score = 2*penality - score;

        return score;
    };

    Packer::SelectionConfig sconf;
//    sconf.allow_parallel = false;
//    sconf.force_parallel = false;
//    sconf.try_triplets = true;
//    sconf.try_reverse_order = true;
//    sconf.waste_increment = 0.005;

    arrange.configure(pconf, sconf);

    arrange.progressIndicator([&](unsigned r){
//        svg::SVGWriter::Config conf;
//        conf.mm_in_coord_units = SCALE;
//        svg::SVGWriter svgw(conf);
//        svgw.setSize(bin);
//        svgw.writePackGroup(arrange.lastResult());
//        svgw.save("debout");
        std::cout << "Remaining items: " << r << std::endl;
    })/*.useMinimumBoundigBoxRotation()*/;

    Benchmark bench;

    bench.start();
    Packer::ResultType result;

    try {
        result = arrange.arrange(input.begin(), input.end());
    } catch(GeometryException& ge) {
        std::cerr << "Geometry error: " << ge.what() << std::endl;
        return ;
    } catch(std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return ;
    }

    bench.stop();

    std::vector<double> eff;
    eff.reserve(result.size());

    auto bin_area = double(bin.height()*bin.width());
    for(auto& r : result) {
        double a = 0;
        std::for_each(r.begin(), r.end(), [&a] (Item& e ){ a += e.area(); });
        eff.emplace_back(a/bin_area);
    };

    std::cout << bench.getElapsedSec() << " bin count: " << result.size()
              << std::endl;

    std::cout << "Bin efficiency: (";
    for(double e : eff) std::cout << e*100.0 << "% ";
    std::cout << ") Average: "
              << std::accumulate(eff.begin(), eff.end(), 0.0)*100.0/result.size()
              << " %" << std::endl;

    std::cout << "Bin usage: (";
    size_t total = 0;
    for(auto& r : result) { std::cout << r.size() << " "; total += r.size(); }
    std::cout << ") Total: " << total << std::endl;

    for(auto& it : input) {
        auto ret = ShapeLike::isValid(it.transformedShape());
        std::cout << ret.second << std::endl;
    }

    if(total != input.size()) std::cout << "ERROR " << "could not pack "
                                        << input.size() - total << " elements!"
                                        << std::endl;

    using SVGWriter = svg::SVGWriter<PolygonImpl>;

    SVGWriter::Config conf;
    conf.mm_in_coord_units = SCALE;
    SVGWriter svgw(conf);
    svgw.setSize(bin);
    svgw.writePackGroup(result);
//    std::for_each(input.begin(), input.end(), [&svgw](Item& item){ svgw.writeItem(item);});
    svgw.save("out");
}

int main(void /*int argc, char **argv*/) {
    arrangeRectangles();
//    findDegenerateCase();

    return EXIT_SUCCESS;
}
