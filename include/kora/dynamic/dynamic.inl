/*
    Copyright (c) 2013-2014 Andrey Goryachev <andrey.goryachev@gmail.com>
    Copyright (c) 2011-2014 Other contributors as noted in the AUTHORS file.

    This file is part of Kora.

    Kora is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Kora is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KORA_DYNAMIC_DYNAMIC_INL
#define KORA_DYNAMIC_DYNAMIC_INL

namespace kora {

namespace detail { namespace dynamic {

struct default_conversion_controller_t {
    void
    start_array(const dynamic_t&) const { }

    void
    finish_array() const { }

    void
    item(size_t) const { }

    void
    start_object(const dynamic_t&) const { }

    void
    finish_object() const { }

    void
    item(const std::string&) const { }

    template<class Exception>
    KORA_NORETURN
    void
    fail(const Exception& e, const dynamic_t&) const {
        throw e;
    }
};

}} // namespace detail::dynamic

template<class T>
dynamic_t::dynamic_t(
    T&& from,
    typename std::enable_if<dynamic_constructor<typename pristine<T>::type>::enable>::type*
) :
    m_value(null_t())
{
    dynamic_constructor<typename pristine<T>::type>::convert(std::forward<T>(from), *this);
}

template<class T>
typename std::enable_if<dynamic_constructor<typename pristine<T>::type>::enable, dynamic_t&>::type
dynamic_t::operator=(T&& from) {
    dynamic_constructor<typename pristine<T>::type>::convert(std::forward<T>(from), *this);
    return *this;
}

template<class T>
bool
dynamic_t::convertible_to() const KORA_NOEXCEPT {
    return dynamic_converter<typename pristine<T>::type>::convertible(*this);
}

template<class T, class Controller>
typename dynamic_converter<typename pristine<T>::type>::result_type
dynamic_t::to(Controller&& controller) const {
    return dynamic_converter<typename pristine<T>::type>::convert(*this, controller);
}

template<class T>
typename dynamic_converter<typename pristine<T>::type>::result_type
dynamic_t::to() const {
    return this->to<T>(detail::dynamic::default_conversion_controller_t());
}

template<class Visitor>
typename std::decay<Visitor>::type::result_type
dynamic_t::apply(Visitor&& visitor) {
    typedef detail::dynamic::dynamic_visitor_applier<Visitor> applier_type;
    return boost::apply_visitor(applier_type(&visitor), m_value);
}

template<class Visitor>
typename std::decay<Visitor>::type::result_type
dynamic_t::apply(Visitor&& visitor) const {
    typedef detail::dynamic::dynamic_visitor_applier<Visitor> applier_type;
    return boost::apply_visitor(applier_type(&visitor), m_value);
}

template<class T>
bool
dynamic_t::is() const {
    return static_cast<bool>(boost::get<T>(&m_value));
}

} // namespace kora

#endif
